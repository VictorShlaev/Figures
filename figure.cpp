#include "figure.hpp"
#include "shaders.hpp"
#include "QDebug"
Figure::Figure(QWidget* parent ):QOpenGLWidget(parent){
}

void Figure::initializeGL()
{
    initializeOpenGLFunctions();
    GLuint vertexShaderId = createShader(vertexShader,GL_VERTEX_SHADER);
    GLuint fragmentShaderId = createShader(fragmentShader,GL_FRAGMENT_SHADER);
    program = createProgram({vertexShaderId, fragmentShaderId});
    glClearColor(0.6, 0.6, 0.6, 1.0);
}

void Figure::paintGL()
{

}
void Figure::resizeGL(int width, int height)
{

}

GLint Figure::bindProgram(const std::vector<GLfloat> &vertexData, std::array<GLuint, 2> &vboIds, size_t index, const std::string name, int coordCnt, GLuint program, int figCnt)
{
    GLuint attribute = glGetAttribLocation(program, name.c_str());
    glBindBuffer(GL_ARRAY_BUFFER, vboIds[index]);
    glBufferData(GL_ARRAY_BUFFER,
                 sizeof(vertexData)*figCnt,
                 vertexData.data(),
                 GL_STATIC_DRAW);
    glVertexAttribPointer(
                attribute,
                coordCnt,
                GL_FLOAT,
                GL_FALSE,
                0,
                nullptr);

    glEnableVertexAttribArray(attribute);
    return attribute;
}

GLuint Figure::createShader(const char *shader, GLenum shaderType)
{
    GLuint shaderId = glCreateShader(shaderType);
    glShaderSource(shaderId,
                   1,
                   &shader,
                   nullptr
                   );
    glCompileShader(shaderId);
    GLint compileOk = GL_FALSE;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compileOk);
    if(compileOk == GL_FALSE){
        qDebug()<<"Shader compile error!";
    }else{
        qDebug()<<"Shader compile ok!";
    }
    return shaderId;
}

GLuint Figure::createProgram(std::vector<GLuint> shadersId)
{
    GLuint program = glCreateProgram();
    for(const auto& Id: shadersId)
        glAttachShader(program, Id);
    glLinkProgram(program);

    GLint linkOk = GL_FALSE;
    glGetProgramiv(program, GL_LINK_STATUS, &linkOk);
    if(linkOk == GL_FALSE){
        qDebug()<<"Link error!";
    }else{
        qDebug()<<"Link ok!";
    }
    return program;
}

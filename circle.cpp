#include "circle.hpp"


//круг реализован путем соединения множества точек линиями
Circle::Circle(formData::Circle form, QWidget *parent):Figure(parent)
{
    radius = form.radius;

}

float Circle::area() const{
    return PI*radius*radius*100*100;
}

float Circle::perimeter() const{
    return  2*PI*radius*100;
}

std::string Circle::figureType() const
{
    return "Circle";
}

Circle::~Circle(){

}

void Circle::paintGL()
{

    uint unVertexArraySize = 500;
    float fDegrees = 0;
    std::vector<GLfloat> fVert(unVertexArraySize*3);
    std::vector<GLfloat> fColor(unVertexArraySize*3);
    // Генерация точек окружности и цветов
    for (size_t i=0; i<fVert.size(); i+=3)
    {
        fVert[i] = std::cos(fDegrees*PI/180.)*radius;
        fVert[i+1] = std::sin(fDegrees*PI/180.)*radius;
        fVert[i+2] = 0.0f;

        fDegrees += (360./unVertexArraySize);

        fColor[i] = 0.51f;
        fColor[i+1] = 0.24f;
        fColor[i+2] = 0.24f;

    }
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(5);
    glUseProgram(program);
    std::array<GLuint, 2> vboIds;
    glGenBuffers(2, vboIds.data());
    GLint attributeCoord2d = bindProgram(fVert, vboIds, 0, "coord2d", 3, program, unVertexArraySize);
    GLint attributeColor = bindProgram(fColor, vboIds, 1, "color",3, program,unVertexArraySize );
    glDrawArrays( GL_LINE_STRIP, 0, unVertexArraySize);
    glDisableVertexAttribArray(attributeCoord2d);
    glDisableVertexAttribArray(attributeColor);
}



#include "rectangle.hpp"
//прямоугольник, из-за моих скудных знаний OpenGL, создается из двух треугольников
Rect::Rect(formData::Rectangle form, QWidget *parent):Figure(parent){
    width = form.width;
    height = form.height;
    vertexes = {
        -width/2, -height/2,
        width/2, height/2,
        -width/2, height/2,

        -width/2, -height/2,
        width/2, height/2,
        width/2, -height/2
    };

    vertexColors = {
        0.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
        0.0, 1.0, 1.0,

        0.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
        0.0, 1.0, 1.0,
    };

}

float Rect::area() const{
    return width*height*100*100;
}

float Rect::perimeter() const{
    return 2*(width+height)*100;
}

std::string Rect::figureType() const
{
    return "Rectangle";
}

Rect::~Rect()
{

}

void Rect::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    std::array<GLuint, 2> vboIds;
    glGenBuffers(2, vboIds.data());
    GLint attributeCoord2d = bindProgram(vertexes, vboIds, 0, "coord2d", 2, program, 2 );
    GLint attributeColor = bindProgram(vertexColors, vboIds, 1, "color",3, program,2);
    glDrawArrays( GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(attributeCoord2d);
    glDisableVertexAttribArray(attributeColor);
}

#include "square.hpp"

//квадрат реализован мной из двух треугольников
Square::Square(formData::Square form, QWidget *parent):Figure(parent)
{
    side = form.side;
    vertexes = {
        -side/2, -side/2,
        side/2, side/2,
        -side/2, side/2,

        -side/2, -side/2,
        side/2, side/2,
        side/2, -side/2
    };

    vertexColors = {
        0.0, 0.0, 1.0,
        1.0, 1.0, 0.0,
        0.0, 1.0, 1.0,

        0.0, 1.0, 1.0,
        1.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };

}

float Square::area() const
{
    return side*side*100*100;
}

float Square::perimeter() const
{
    return 4*side*100;
}

std::string Square::figureType() const
{
    return "Square";
}

Square::~Square(){
}

void Square::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    std::array<GLuint, 2> vboIds;
    glGenBuffers(2, vboIds.data());
    GLint attributeCoord2d = bindProgram(vertexes, vboIds, 0, "coord2d", 2, program, 2 );
    GLint attributeColor = bindProgram(vertexColors, vboIds, 1, "color",3, program, 2 );
    glDrawArrays( GL_TRIANGLES, 0, 6);
    glDisableVertexAttribArray(attributeCoord2d);
    glDisableVertexAttribArray(attributeColor);
}


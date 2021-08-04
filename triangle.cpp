#include "triangle.hpp"
#include <QDebug>
Triangle::Triangle(formData::Triangle form, QWidget* parent): Figure(parent)
{
    a = distance(form.cx,form.cy, form.bx, form.by);
    b = distance(form.ax, form.ay, form.cx, form.cy);
    c = distance(form.ax, form.ay, form.bx, form.by);
    qDebug()<<" a: "<<a<<" b: "<<b<<" c: "<<c;
    if (a + b > c and a + c > b and b + c > a){
        triangleVertexes = {
            form.ax, form.ay,
            form.bx, form.by,
            form.cx, form.cy
        };
        triangleColors={
            0.0, 0.0, 1.0,
            0.0, 1.0, 0.0,
            1.0, 0.0, 1.0
        };

    }else{
        throw std::invalid_argument("The condition for the existence of a triangle is violated!");
    }
}

float Triangle::area() const
{
    float p = perimeter()/2.;//полупериметр
    //формула Герона для поиска площади треугольника через полупериметр
    return std::sqrt(p*(p-a*100)*(p-b*100)*(p-c*100));
}

float Triangle::perimeter() const
{
    return (a+b+c)*100;
}

std::string Triangle::figureType() const
{
    return "Triangle";
}

void Triangle::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(program);
    std::array<GLuint, 2> vboIds;
    glGenBuffers(2, vboIds.data());
    GLint attributeCoord2d = bindProgram(triangleVertexes, vboIds, 0, "coord2d", 2, program );
    GLint attributeColor = bindProgram(triangleColors, vboIds, 1, "color", 3, program );
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(attributeCoord2d);
    glDisableVertexAttribArray(attributeColor);
}

double Triangle::distance(float x1, float y1, float x2, float y2)
{
    return std::sqrt(std::pow(x2-x1,2)+std::pow(y2-y1,2));
}

Triangle::~Triangle()
{

}


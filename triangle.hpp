#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cmath>
#include "figure.hpp"
//класс треугольника
class Triangle : public Figure
{
public:
    Triangle( formData::Triangle fData, QWidget *parent = nullptr);
    float area() const override;
    float perimeter() const override;
    std::string figureType() const override;
    virtual ~Triangle();
protected:
    void paintGL() override;
private:
    std::vector<GLfloat> triangleVertexes; //вектор координат вершин
    std::vector<GLfloat> triangleColors;   //вектор цветов вершин
    float a;                               //длина стороны a в у.е.
    float b;                               //длина стороны b в у.е.
    float c;                               //длина стороны c в у.е.
private:
    //функция поиска расстояния между вершинами треугольника
    double distance(float x1, float x2, float y1, float y2);

};



#endif // TRIANGLE_HPP

#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "figure.hpp"
#include <cmath>
//класс круга
class Circle:public Figure
{
public:
    Circle(formData::Circle form, QWidget* parent = nullptr);
    //переопределенные методы
    float area() const override;            //площадь круга
    float perimeter() const override;       //длина окружности
    std::string figureType() const override;//тип фигуры
    virtual ~Circle();
protected:
    void paintGL() override;
private:
     const float PI = 3.14159265359; //константа
     float radius;                   //радиус окружности

};

#endif // CIRCLE_HPP

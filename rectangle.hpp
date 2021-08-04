#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "figure.hpp"
//класс прямоугольника
class Rect : public Figure
{
public:
    Rect(formData::Rectangle form, QWidget* parent = nullptr);
    //переопределенные функции базового класса
    float area() const override;
    float perimeter() const override;
    std::string figureType() const override;
    virtual ~Rect();
protected:
    void paintGL() override;
private:
    float width;                                //ширина прямоугольника в у.е.
    float height;                               //высота прямоугольника в у.е.
    std::vector<GLfloat> vertexes;              //вектор координат
    std::vector<GLfloat> vertexColors;          //вектор цветов
};

#endif // RECTANGLE_HPP

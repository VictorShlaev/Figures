#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "figure.hpp"
//класс квадрата
class Square: public Figure
{
public:
    Square(formData::Square form, QWidget* parent = nullptr);
    //переопределенные методы базового класса
    float area() const override;
    float perimeter() const override;
    std::string figureType() const override;
    virtual ~Square();
protected:
    void paintGL() override;
private:
    float side;                                 //длина квадрата в у.е.
    std::vector<GLfloat> vertexes;              //вектор координат
    std::vector<GLfloat> vertexColors;          //вектор цветов
};

#endif // SQUARE_HPP

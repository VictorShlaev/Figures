#ifndef FIGURE_HPP
#define FIGURE_HPP
#include <string>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "formData.hpp"

class Figure:public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    Figure(QWidget* parent = nullptr);
    virtual float area() const = 0;             //функция поиска площади
    virtual float perimeter() const = 0;        //функция поиска периметра
    virtual std::string figureType() const = 0; //функция, возвращающая название фигуры
    virtual ~Figure() = default;
protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    // функция paintGL объявлена виртуальной,
    // т.к. ее необходимо переопределить для корректной отрисовки
    virtual void paintGL() override;
    //функция связывания переменных шейдера и данных
    GLint bindProgram(const std::vector<GLfloat>& vertexData, //вектор координат или цветов
                      std::array<GLuint, 2>& vboIds,          //vbo массив для вершин и цвета
                      size_t index,                           //индекс в vbo массиве, 0-координаты, 1-цвет
                      const std::string name,                 //название переменной в шейдере
                      int coordCnt,                           //количество координат, используемых в соответствующем векторе
                      GLuint program,                         //переменная шейдерной программы
                      int figCnt = 1                          //коэффициент размера буфера
            );
private:
    //функция компиляции шейдерного исходного кода
    GLuint createShader(const char* shader, //исходник шейдера
                        GLenum shaderType   //тип шейдера
                        );
    //функция создает шейдерную программу из шейдеров
    GLuint createProgram(std::vector<GLuint> shadersId);
protected:
    GLuint program;

};

#endif // FIGURE_HPP

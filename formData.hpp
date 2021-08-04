#ifndef FORMDATA_HPP
#define FORMDATA_HPP
// структуры данных, для записи соответственных значений из формы
// и последующей передачи в соответствующие классы фигур
namespace formData {
    struct Circle{
        float radius;
    };

    struct Triangle{
        float ax;
        float ay;
        float bx;
        float by;
        float cx;
        float cy;
    };

    struct Square{
        float side;
    };

    struct Rectangle{
        float width;
        float height;
    };
}
#endif // FORMDATA_HPP

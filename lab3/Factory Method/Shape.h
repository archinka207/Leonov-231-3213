#ifndef SHAPE_H
#define SHAPE_H

#include <string>

// Интерфейс Продукта
class Shape {
public:
    virtual ~Shape() = default;

    // Метод отрисовки (вывода в консоль)
    virtual void draw() const = 0;

    // Получение имени фигуры
    virtual std::string getName() const = 0;
};

#endif // SHAPE_H
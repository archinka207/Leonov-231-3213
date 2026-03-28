#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include "Shape.h"
#include <memory>

// Интерфейс Создателя (Creator)
class ShapeFactory {
public:
    virtual ~ShapeFactory() = default;

    // Фабричный метод
    virtual std::unique_ptr<Shape> createShape() const = 0;
};

#endif // SHAPE_FACTORY_H
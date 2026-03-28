#ifndef CONCRETE_FACTORIES_H
#define CONCRETE_FACTORIES_H

#include "ShapeFactory.h"
#include <random>

// Фабрика для стандартных фигур
class StandardShapeFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() const override;
};

// Фабрика для супер-фигур
class SuperShapeFactory : public ShapeFactory {
public:
    std::unique_ptr<Shape> createShape() const override;
};

#endif // CONCRETE_FACTORIES_H
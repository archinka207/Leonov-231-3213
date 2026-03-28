#ifndef CONCRETE_SHAPES_H
#define CONCRETE_SHAPES_H

#include "Shape.h"

// --- Стандартные фигуры (Тетрамино - 4 клетки) ---

class ShapeI : public Shape {
public:
    void draw() const override;
    std::string getName() const override { return "I-Shape (Standard)"; }
};

class ShapeO : public Shape {
public:
    void draw() const override;
    std::string getName() const override { return "O-Shape (Standard)"; }
};

class ShapeT : public Shape {
public:
    void draw() const override;
    std::string getName() const override { return "T-Shape (Standard)"; }
};

class ShapeL : public Shape {
public:
    void draw() const override;
    std::string getName() const override { return "L-Shape (Standard)"; }
};

// --- Супер-фигуры (Пентамино - 5 клеток) ---

class SuperShapeX : public Shape {
public:
    void draw() const override;
    std::string getName() const override { return "X-Shape (SUPER - 5 blocks)"; }
};

class SuperShapeLong : public Shape {
public:
    void draw() const override;
    std::string getName() const override { return "Long-Shape (SUPER - 5 blocks)"; }
};

#endif // CONCRETE_SHAPES_H
#include "ConcreteFactories.h"
#include "ConcreteShapes.h"
#include <random>

// Вспомогательная функция для получения случайного числа
int getRandomInt(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

// --- StandardShapeFactory ---
// Возвращает одну из стандартных фигур (I, O, T, L)
std::unique_ptr<Shape> StandardShapeFactory::createShape() const {
    int choice = getRandomInt(0, 3);
    switch (choice) {
        case 0: return std::make_unique<ShapeI>();
        case 1: return std::make_unique<ShapeO>();
        case 2: return std::make_unique<ShapeT>();
        case 3: return std::make_unique<ShapeL>();
        default: return std::make_unique<ShapeI>();
    }
}

// --- SuperShapeFactory ---
// Возвращает одну из супер-фигур
std::unique_ptr<Shape> SuperShapeFactory::createShape() const {
    int choice = getRandomInt(0, 1);
    switch (choice) {
        case 0: return std::make_unique<SuperShapeX>();
        case 1: return std::make_unique<SuperShapeLong>();
        default: return std::make_unique<SuperShapeX>();
    }
}
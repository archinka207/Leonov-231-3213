#include "ConcreteShapes.h"
#include <iostream>

// Реализация отрисовки для стандартных фигур

void ShapeI::draw() const {
    std::cout << "  []\n  []\n  []\n  []\n";
}

void ShapeO::draw() const {
    std::cout << "  [][] \n  [][] \n";
}

void ShapeT::draw() const {
    std::cout << "  [][][] \n    []   \n";
}

void ShapeL::draw() const {
    std::cout << "  []   \n  []   \n  [][] \n";
}

// Реализация отрисовки для супер-фигур

void SuperShapeX::draw() const {
    std::cout << "    []   \n  [][][] \n    []   \n";
}

void SuperShapeLong::draw() const {
    std::cout << "  []\n  []\n  []\n  []\n  []\n";
}
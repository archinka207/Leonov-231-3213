#include <iostream>
#include <vector>
#include <memory>
#include <ctime>
#include "ConcreteFactories.h"

// Функция для имитации игровой логики
// Иногда игра требует обычную фигуру, иногда (реже) дает бонусную супер-фигуру
void runGameLevel(int numberOfShapes) {
    StandardShapeFactory standardFactory;
    SuperShapeFactory superFactory;

    std::srand(std::time(nullptr)); // Для простой рандомизации выбора фабрики

    std::cout << "--- TETRIS GAME START ---\n" << std::endl;

    for (int i = 0; i < numberOfShapes; ++i) {
        std::unique_ptr<Shape> currentShape;

        // Логика игры: с вероятностью 20% появляется супер-фигура
        // Клиентский код решает, какую фабрику использовать, но не знает, 
        // какой конкретно класс фигуры вернет фабрика.
        bool isSuperEvent = (std::rand() % 100) < 20;

        if (isSuperEvent) {
            std::cout << "[Event] Super Factory Activated!" << std::endl;
            currentShape = superFactory.createShape();
        } else {
            currentShape = standardFactory.createShape();
        }

        std::cout << "Next shape: " << currentShape->getName() << std::endl;
        currentShape->draw();
        std::cout << "-------------------------" << std::endl;
    }
}

int main() {
    runGameLevel(10); // Генерируем 10 фигур
    return 0;
}
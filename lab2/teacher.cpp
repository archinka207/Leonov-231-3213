#include "teacher.h"

Teacher::Teacher(const std::string& name) : Person(name) {}

void Teacher::teach() const {
    std::cout << "[Преподаватель] " << name << " объясняет материал у доски." << std::endl;
}

std::string Teacher::getName() const {
    return Person::getName();
}
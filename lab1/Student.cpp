#include "Student.h"
#include <string> // Добавлено, так как std::string используется
// <vector> не нужна здесь, только в .h, если есть вектор в самом классе

Student::Student(const std::string& name, const std::string& id)
    : id(id), name(name) {}

const std::string& Student::getId() const {
    return id;
}

const std::string& Student::getName() const {
    return name;
}

void Student::setName(const std::string& name) {
    this->name = name;
}
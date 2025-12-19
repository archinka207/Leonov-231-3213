#include "student.h"

Student::Student(const std::string& name) : Person(name) {}

void Student::study() const {
    std::cout << "[Студент] " << name << " конспектирует лекцию." << std::endl;
}

std::string Student::getName() const {
    return Person::getName();
}
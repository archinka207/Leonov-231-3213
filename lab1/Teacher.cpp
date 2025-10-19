#include "Teacher.h"
#include <string> // Добавлено

Teacher::Teacher(const std::string& name, const std::string& id)
    : id(id), name(name) {}

const std::string& Teacher::getId() const {
    return id;
}

const std::string& Teacher::getName() const {
    return name;
}

void Teacher::setName(const std::string& name) {
    this->name = name;
}
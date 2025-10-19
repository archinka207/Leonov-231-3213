#include "Course.h"
#include <string> // Добавлено

Course::Course(const std::string& title, const std::string& teacherId, const std::string& id)
    : id(id), title(title), teacherId(teacherId) {}

const std::string& Course::getId() const {
    return id;
}

const std::string& Course::getTitle() const {
    return title;
}

void Course::setTitle(const std::string& title) {
    this->title = title;
}

const std::string& Course::getTeacherId() const {
    return teacherId;
}

void Course::setTeacherId(const std::string& teacherId) {
    this->teacherId = teacherId;
}
#include "Enrollment.h"
#include <string>   // Добавлено
#include <optional> // Добавлено, так как std::optional используется

Enrollment::Enrollment(const std::string& studentId, const std::string& courseId, const std::string& id)
    : id(id), studentId(studentId), courseId(courseId) {}

const std::string& Enrollment::getId() const {
    return id;
}

const std::string& Enrollment::getStudentId() const {
    return studentId;
}

const std::string& Enrollment::getCourseId() const {
    return courseId;
}

std::optional<int> Enrollment::getGrade() const {
    return grade;
}

void Enrollment::setGrade(int grade) {
    if (grade >= 0 && grade <= 100) { // Пример валидации оценки
        this->grade = grade;
    } else {
        this->grade.reset(); // Сбросить оценку, если она невалидна
    }
}
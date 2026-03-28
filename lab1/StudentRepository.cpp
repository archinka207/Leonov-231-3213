#include "StudentRepository.h"
#include <algorithm>
#include <iostream>
#include <memory>   // Добавлено для std::shared_ptr
#include <string>   // Добавлено для std::string
#include <vector>   // Добавлено для std::vector
#include "Student.h" // Убедиться, что Student включен, так как репозиторий его использует

void StudentRepository::addStudent(std::shared_ptr<Student> student) {
    if (!student) {
        std::cerr << "Error: Attempted to add a null student." << std::endl;
        return;
    }
    students.push_back(student);
}

std::shared_ptr<Student> StudentRepository::getStudentById(const std::string& id) {
    for (const auto& student : students) {
        if (student->getId() == id) {
            return student;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Student>> StudentRepository::getAllStudents() const {
    return students;
}

void StudentRepository::updateStudent(std::shared_ptr<Student> updatedStudent) {
    if (!updatedStudent) {
        std::cerr << "Error: Attempted to update with a null student object." << std::endl;
        return;
    }
    for (auto& student : students) {
        if (student->getId() == updatedStudent->getId()) {
            student->setName(updatedStudent->getName());
            return;
        }
    }
    std::cerr << "Warning: Student with ID " << updatedStudent->getId() << " not found for update." << std::endl;
}

void StudentRepository::deleteStudent(const std::string& id) {
    auto it = std::remove_if(students.begin(), students.end(),
                             [&id](const std::shared_ptr<Student>& student) {
                                 return student->getId() == id;
                             });
    if (it != students.end()) {
        students.erase(it, students.end());
    } else {
        std::cerr << "Warning: Student with ID " << id << " not found for deletion." << std::endl;
    }
}
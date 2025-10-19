#include "TeacherRepository.h"
#include <algorithm>
#include <iostream>
#include <memory>   // Добавлено для std::shared_ptr
#include <string>   // Добавлено для std::string
#include <vector>   // Добавлено для std::vector
#include "Teacher.h" // Убедиться, что Teacher включен

void TeacherRepository::addTeacher(std::shared_ptr<Teacher> teacher) {
    if (!teacher) {
        std::cerr << "Error: Attempted to add a null teacher." << std::endl;
        return;
    }
    teachers.push_back(teacher);
}

std::shared_ptr<Teacher> TeacherRepository::getTeacherById(const std::string& id) {
    for (const auto& teacher : teachers) {
        if (teacher->getId() == id) {
            return teacher;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Teacher>> TeacherRepository::getAllTeachers() const {
    return teachers;
}

void TeacherRepository::updateTeacher(std::shared_ptr<Teacher> updatedTeacher) {
    if (!updatedTeacher) {
        std::cerr << "Error: Attempted to update with a null teacher object." << std::endl;
        return;
    }
    for (auto& teacher : teachers) {
        if (teacher->getId() == updatedTeacher->getId()) {
            teacher->setName(updatedTeacher->getName());
            return;
        }
    }
    std::cerr << "Warning: Teacher with ID " << updatedTeacher->getId() << " not found for update." << std::endl;
}

void TeacherRepository::deleteTeacher(const std::string& id) {
    auto it = std::remove_if(teachers.begin(), teachers.end(),
                             [&id](const std::shared_ptr<Teacher>& teacher) {
                                 return teacher->getId() == id;
                             });
    if (it != teachers.end()) {
        teachers.erase(it, teachers.end());
    } else {
        std::cerr << "Warning: Teacher with ID " << id << " not found for deletion." << std::endl;
    }
}
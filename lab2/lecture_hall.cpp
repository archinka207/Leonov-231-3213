#include "lecture_hall.h"
#include <iostream>

LectureHall::LectureHall(ITeacher* t) : teacher(t) {}

void LectureHall::addStudent(ILearner* s) {
    learners.push_back(s);
}

void LectureHall::startLesson() {
    std::cout << "\n--- Начало занятия ---" << std::endl;
    if (teacher) {
        // Полиморфный вызов. LectureHall не знает, кто именно преподает.
        teacher->teach(); 
    }
    
    std::cout << "Группа приступает к работе:" << std::endl;
    for (const auto& student : learners) {
        student->study();
    }
    std::cout << "--- Конец занятия ---\n" << std::endl;
}
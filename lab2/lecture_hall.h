#ifndef LECTURE_HALL_H
#define LECTURE_HALL_H

#include <vector>
#include "interfaces.h"

class LectureHall {
private:
    ITeacher* teacher;                 // Зависимость от абстракции (DIP)
    std::vector<ILearner*> learners;   // Зависимость от абстракции (DIP)

public:
    // Внедрение зависимости через конструктор (Dependency Injection)
    LectureHall(ITeacher* t);

    void addStudent(ILearner* s);
    void startLesson();
};

#endif
#ifndef TEACHER_H
#define TEACHER_H

#include "person.h"
#include "interfaces.h"

class Teacher : public Person, public ITeacher {
public:
    Teacher(const std::string& name);

    // Реализация ITeacher
    void teach() const override;
    std::string getName() const override;
};

#endif
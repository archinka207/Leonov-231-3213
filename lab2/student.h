#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"
#include "interfaces.h"

class Student : public Person, public ILearner {
public:
    Student(const std::string& name);
    
    // Реализация ILearner
    void study() const override;
    std::string getName() const override; // Разрешение неоднозначности наследования
};

#endif
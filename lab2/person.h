#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person {
protected:
    std::string name;
public:
    Person(const std::string& name);
    virtual ~Person() = default;
    
    virtual std::string getName() const;
};

#endif
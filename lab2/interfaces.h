#ifndef INTERFACES_H
#define INTERFACES_H

#include <string>

// Интерфейс для тех, кто учится
class ILearner {
public:
    virtual void study() const = 0;
    virtual std::string getName() const = 0;
    virtual ~ILearner() = default;
};

// Интерфейс для тех, кто преподает
class ITeacher {
public:
    virtual void teach() const = 0;
    virtual std::string getName() const = 0;
    virtual ~ITeacher() = default;
};

// Интерфейс для управленцев
class IManager {
public:
    virtual void manage() const = 0;
    virtual std::string getName() const = 0;
    virtual ~IManager() = default;
};

#endif
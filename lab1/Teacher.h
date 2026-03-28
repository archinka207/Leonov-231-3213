#ifndef TEACHER_H
#define TEACHER_H

#include <string>

class Teacher {
public:
    Teacher(const std::string& name, const std::string& id);

    const std::string& getId() const;
    const std::string& getName() const;
    void setName(const std::string& name);

private:
    std::string id;
    std::string name;
};

#endif // TEACHER_H
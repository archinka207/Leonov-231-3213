#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

class Student {
public:
    Student(const std::string& name, const std::string& id);

    const std::string& getId() const;
    const std::string& getName() const;
    void setName(const std::string& name);

private:
    std::string id;
    std::string name;
};

#endif // STUDENT_H
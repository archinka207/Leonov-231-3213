#ifndef TEACHER_REPOSITORY_H
#define TEACHER_REPOSITORY_H

#include "Teacher.h"
#include <vector>
#include <string>
#include <memory>

class TeacherRepository {
public:
    void addTeacher(std::shared_ptr<Teacher> teacher);
    std::shared_ptr<Teacher> getTeacherById(const std::string& id);
    std::vector<std::shared_ptr<Teacher>> getAllTeachers() const;
    void updateTeacher(std::shared_ptr<Teacher> teacher);
    void deleteTeacher(const std::string& id);

private:
    std::vector<std::shared_ptr<Teacher>> teachers;
};

#endif // TEACHER_REPOSITORY_H
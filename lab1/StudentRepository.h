#ifndef STUDENT_REPOSITORY_H
#define STUDENT_REPOSITORY_H

#include "Student.h"
#include <vector>
#include <string>
#include <memory> // Для std::shared_ptr

class StudentRepository {
public:
    void addStudent(std::shared_ptr<Student> student);
    std::shared_ptr<Student> getStudentById(const std::string& id);
    std::vector<std::shared_ptr<Student>> getAllStudents() const;
    void updateStudent(std::shared_ptr<Student> student);
    void deleteStudent(const std::string& id);

private:
    std::vector<std::shared_ptr<Student>> students;
};

#endif // STUDENT_REPOSITORY_H
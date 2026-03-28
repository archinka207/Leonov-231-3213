#ifndef ENROLLMENT_SERVICE_H
#define ENROLLMENT_SERVICE_H

#include "EnrollmentRepository.h"
#include "StudentRepository.h"
#include "CourseRepository.h"
#include "IdGenerator.h"
#include <string>
#include <memory>
#include <vector>

class EnrollmentService {
public:
    EnrollmentService(std::shared_ptr<EnrollmentRepository> enrollmentRepo,
                      std::shared_ptr<StudentRepository> studentRepo,
                      std::shared_ptr<CourseRepository> courseRepo);

    // Студент записывается на Курс
    std::shared_ptr<Enrollment> enrollStudent(const std::string& studentId, const std::string& courseId);
    
    // Преподаватель выставляет Оценку
    bool assignGrade(const std::string& enrollmentId, int grade);
    bool assignGrade(const std::string& studentId, const std::string& courseId, int grade);

    // Получить записи студента
    std::vector<std::shared_ptr<Enrollment>> getStudentEnrollments(const std::string& studentId) const;
    
    // Получить студентов на курсе
    std::vector<std::shared_ptr<Student>> getStudentsInCourse(const std::string& courseId) const;
    
    // Получить все записи (Архив)
    std::vector<std::shared_ptr<Enrollment>> getArchive() const;

private:
    std::shared_ptr<EnrollmentRepository> enrollmentRepository;
    std::shared_ptr<StudentRepository> studentRepository;
    std::shared_ptr<CourseRepository> courseRepository;
};

#endif // ENROLLMENT_SERVICE_H
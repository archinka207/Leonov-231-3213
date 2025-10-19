#include "EnrollmentService.h"
#include <iostream>
#include <algorithm> // Для std::find_if
#include <stdexcept> // Для std::runtime_error

EnrollmentService::EnrollmentService(std::shared_ptr<EnrollmentRepository> enrollmentRepo,
                                     std::shared_ptr<StudentRepository> studentRepo,
                                     std::shared_ptr<CourseRepository> courseRepo)
    // Исправлено: имена параметров должны совпадать с именами в объявлении конструктора
    : enrollmentRepository(enrollmentRepo), studentRepository(studentRepo), courseRepository(courseRepo) {
    if (!enrollmentRepository || !studentRepository || !courseRepository) {
        throw std::runtime_error("One or more repositories are null.");
    }
}

std::shared_ptr<Enrollment> EnrollmentService::enrollStudent(const std::string& studentId, const std::string& courseId) {
    // Проверка существования студента
    if (!studentRepository->getStudentById(studentId)) {
        std::cerr << "Error: Student with ID " << studentId << " not found. Cannot enroll." << std::endl;
        return nullptr;
    }
    // Проверка существования курса
    if (!courseRepository->getCourseById(courseId)) {
        std::cerr << "Error: Course with ID " << courseId << " not found. Cannot enroll." << std::endl;
        return nullptr;
    }

    // Проверка, не записан ли студент уже на этот курс
    if (enrollmentRepository->getEnrollmentByStudentAndCourse(studentId, courseId)) {
        std::cerr << "Warning: Student " << studentId << " is already enrolled in course " << courseId << "." << std::endl;
        return nullptr;
    }

    std::string enrollmentId = IdGenerator::generateId();
    auto newEnrollment = std::make_shared<Enrollment>(studentId, courseId, enrollmentId);
    enrollmentRepository->addEnrollment(newEnrollment);
    std::cout << "Student " << studentId << " enrolled in course " << courseId << ". Enrollment ID: " << enrollmentId << std::endl;
    return newEnrollment;
}

bool EnrollmentService::assignGrade(const std::string& enrollmentId, int grade) {
    auto enrollment = enrollmentRepository->getEnrollmentById(enrollmentId);
    if (!enrollment) {
        std::cerr << "Error: Enrollment with ID " << enrollmentId << " not found to assign grade." << std::endl;
        return false;
    }
    enrollment->setGrade(grade);
    enrollmentRepository->updateEnrollment(enrollment);
    std::cout << "Grade " << grade << " assigned to enrollment " << enrollmentId << std::endl;
    return true;
}

bool EnrollmentService::assignGrade(const std::string& studentId, const std::string& courseId, int grade) {
    auto enrollment = enrollmentRepository->getEnrollmentByStudentAndCourse(studentId, courseId);
    if (!enrollment) {
        std::cerr << "Error: Enrollment for student " << studentId << " on course " << courseId << " not found to assign grade." << std::endl;
        return false;
    }
    enrollment->setGrade(grade);
    enrollmentRepository->updateEnrollment(enrollment);
    std::cout << "Grade " << grade << " assigned to student " << studentId << " for course " << courseId << std::endl;
    return true;
}

std::vector<std::shared_ptr<Enrollment>> EnrollmentService::getStudentEnrollments(const std::string& studentId) const {
    return enrollmentRepository->getEnrollmentsByStudentId(studentId);
}

std::vector<std::shared_ptr<Student>> EnrollmentService::getStudentsInCourse(const std::string& courseId) const {
    std::vector<std::shared_ptr<Student>> studentsInCourse;
    auto enrollments = enrollmentRepository->getEnrollmentsByCourseId(courseId);
    for (const auto& enrollment : enrollments) {
        if (auto student = studentRepository->getStudentById(enrollment->getStudentId())) {
            studentsInCourse.push_back(student);
        }
    }
    return studentsInCourse;
}

std::vector<std::shared_ptr<Enrollment>> EnrollmentService::getArchive() const {
    return enrollmentRepository->getAllEnrollments();
}
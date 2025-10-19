#include "EnrollmentRepository.h"
#include <algorithm>
#include <iostream>
#include <memory>   // Добавлено для std::shared_ptr
#include <string>   // Добавлено для std::string
#include <vector>   // Добавлено для std::vector
#include "Enrollment.h" // Добавлено
// #include "Student.h" // Не нужны здесь, так как EnrollmentRepository работает с Enrollment, а не напрямую со Student/Course объектами
// #include "Course.h"

void EnrollmentRepository::addEnrollment(std::shared_ptr<Enrollment> enrollment) {
    if (!enrollment) {
        std::cerr << "Error: Attempted to add a null enrollment." << std::endl;
        return;
    }
    enrollments.push_back(enrollment);
}

std::shared_ptr<Enrollment> EnrollmentRepository::getEnrollmentById(const std::string& id) {
    for (const auto& enrollment : enrollments) {
        if (enrollment->getId() == id) {
            return enrollment;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Enrollment>> EnrollmentRepository::getAllEnrollments() const {
    return enrollments;
}

void EnrollmentRepository::updateEnrollment(std::shared_ptr<Enrollment> updatedEnrollment) {
    if (!updatedEnrollment) {
        std::cerr << "Error: Attempted to update with a null enrollment object." << std::endl;
        return;
    }
    for (auto& enrollment : enrollments) {
        if (enrollment->getId() == updatedEnrollment->getId()) {
            enrollment->setGrade(updatedEnrollment->getGrade().value_or(-1));
            return;
        }
    }
    std::cerr << "Warning: Enrollment with ID " << updatedEnrollment->getId() << " not found for update." << std::endl;
}

void EnrollmentRepository::deleteEnrollment(const std::string& id) {
    auto it = std::remove_if(enrollments.begin(), enrollments.end(),
                             [&id](const std::shared_ptr<Enrollment>& enrollment) {
                                 return enrollment->getId() == id;
                             });
    if (it != enrollments.end()) {
        enrollments.erase(it, enrollments.end());
    } else {
        std::cerr << "Warning: Enrollment with ID " << id << " not found for deletion." << std::endl;
    }
}

std::vector<std::shared_ptr<Enrollment>> EnrollmentRepository::getEnrollmentsByStudentId(const std::string& studentId) const {
    std::vector<std::shared_ptr<Enrollment>> studentEnrollments;
    for (const auto& enrollment : enrollments) {
        if (enrollment->getStudentId() == studentId) {
            studentEnrollments.push_back(enrollment);
        }
    }
    return studentEnrollments;
}

std::vector<std::shared_ptr<Enrollment>> EnrollmentRepository::getEnrollmentsByCourseId(const std::string& courseId) const {
    std::vector<std::shared_ptr<Enrollment>> courseEnrollments;
    for (const auto& enrollment : enrollments) {
        if (enrollment->getCourseId() == courseId) {
            courseEnrollments.push_back(enrollment);
        }
    }
    return courseEnrollments;
}

std::shared_ptr<Enrollment> EnrollmentRepository::getEnrollmentByStudentAndCourse(const std::string& studentId, const std::string& courseId) const {
    for (const auto& enrollment : enrollments) {
        if (enrollment->getStudentId() == studentId && enrollment->getCourseId() == courseId) {
            return enrollment;
        }
    }
    return nullptr;
}
#ifndef ENROLLMENT_REPOSITORY_H
#define ENROLLMENT_REPOSITORY_H

#include "Enrollment.h"
#include <vector>
#include <string>
#include <memory>

// В данном контексте EnrollmentRepository также выступает в роли "Архива"
// так как хранит все записи с оценками.

class EnrollmentRepository {
public:
    void addEnrollment(std::shared_ptr<Enrollment> enrollment);
    std::shared_ptr<Enrollment> getEnrollmentById(const std::string& id);
    std::vector<std::shared_ptr<Enrollment>> getAllEnrollments() const;
    void updateEnrollment(std::shared_ptr<Enrollment> enrollment);
    void deleteEnrollment(const std::string& id);

    std::vector<std::shared_ptr<Enrollment>> getEnrollmentsByStudentId(const std::string& studentId) const;
    std::vector<std::shared_ptr<Enrollment>> getEnrollmentsByCourseId(const std::string& courseId) const;
    std::shared_ptr<Enrollment> getEnrollmentByStudentAndCourse(const std::string& studentId, const std::string& courseId) const;

private:
    std::vector<std::shared_ptr<Enrollment>> enrollments;
};

#endif // ENROLLMENT_REPOSITORY_H
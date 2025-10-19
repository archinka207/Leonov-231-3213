#ifndef COURSE_MANAGEMENT_SERVICE_H
#define COURSE_MANAGEMENT_SERVICE_H

#include "CourseRepository.h"
#include "TeacherRepository.h"
#include "IdGenerator.h"
#include <string>
#include <memory>
#include <vector>

class CourseManagementService {
public:
    CourseManagementService(std::shared_ptr<CourseRepository> courseRepo,
                            std::shared_ptr<TeacherRepository> teacherRepo);

    std::shared_ptr<Course> createCourse(const std::string& title, const std::string& teacherId);
    bool updateCourseDetails(const std::string& courseId, const std::string& newTitle, const std::string& newTeacherId);
    bool removeCourse(const std::string& courseId);
    std::vector<std::shared_ptr<Course>> getCoursesTaughtBy(const std::string& teacherId) const;
    std::shared_ptr<Course> getCourseDetails(const std::string& courseId) const;
    std::vector<std::shared_ptr<Course>> getAllAvailableCourses() const;

private:
    std::shared_ptr<CourseRepository> courseRepository;
    std::shared_ptr<TeacherRepository> teacherRepository; // Используется для проверки существования учителя
};

#endif // COURSE_MANAGEMENT_SERVICE_H
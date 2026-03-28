#ifndef COURSE_REPOSITORY_H
#define COURSE_REPOSITORY_H

#include "Course.h"   // Обязательно для объявления класса Course
#include <vector>     // Для std::vector
#include <string>     // Для std::string
#include <memory>     // Для std::shared_ptr

class CourseRepository {
public:
    // Изменено имя параметра с 'courses' на 'course' для ясности
    void addCourse(std::shared_ptr<Course> course);
    std::shared_ptr<Course> getCourseById(const std::string& id) const; // Добавлен const
    std::vector<std::shared_ptr<Course>> getAllCourses() const;
    void updateCourse(std::shared_ptr<Course> updatedCourse);
    void deleteCourse(const std::string& id);
    std::vector<std::shared_ptr<Course>> getCoursesByTeacherId(const std::string& teacherId) const;

private:
    std::vector<std::shared_ptr<Course>> courses;
};

#endif // COURSE_REPOSITORY_H
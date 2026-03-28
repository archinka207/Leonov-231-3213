#include "CourseManagementService.h" // Включаем свой заголовочный файл
#include <iostream>
#include <string>    // Для std::string
#include <memory>    // Для std::shared_ptr
#include <vector>    // Для std::vector
#include <stdexcept> // Для std::runtime_error

// Также убедитесь, что все репозитории и сущности, с которыми работает сервис, включены
#include "IdGenerator.h"
#include "Course.h"
#include "Teacher.h"
// Репозитории уже включены через CourseManagementService.h, но можно явно указать, если есть проблемы
// #include "CourseRepository.h"
// #include "TeacherRepository.h"

CourseManagementService::CourseManagementService(std::shared_ptr<CourseRepository> courseRepo,
                                                 std::shared_ptr<TeacherRepository> teacherRepo)
    : courseRepository(courseRepo), teacherRepository(teacherRepo) {
    if (!courseRepository || !teacherRepository) {
        throw std::runtime_error("CourseRepository or TeacherRepository cannot be null.");
    }
}

std::shared_ptr<Course> CourseManagementService::createCourse(const std::string& title, const std::string& teacherId) {
    if (!teacherRepository->getTeacherById(teacherId)) {
        std::cerr << "Error: Teacher with ID " << teacherId << " not found. Cannot create course." << std::endl;
        return nullptr;
    }

    std::string courseId = IdGenerator::generateId();
    auto newCourse = std::make_shared<Course>(title, teacherId, courseId);
    courseRepository->addCourse(newCourse);
    std::cout << "Course '" << title << "' created with ID: " << courseId << " by teacher ID: " << teacherId << std::endl;
    return newCourse;
}

bool CourseManagementService::updateCourseDetails(const std::string& courseId, const std::string& newTitle, const std::string& newTeacherId) {
    auto course = courseRepository->getCourseById(courseId);
    if (!course) {
        std::cerr << "Error: Course with ID " << courseId << " not found for update." << std::endl;
        return false;
    }

    if (!teacherRepository->getTeacherById(newTeacherId)) {
        std::cerr << "Error: New teacher with ID " << newTeacherId << " not found. Cannot update course." << std::endl;
        return false;
    }

    course->setTitle(newTitle);
    course->setTeacherId(newTeacherId);
    courseRepository->updateCourse(course);
    std::cout << "Course " << courseId << " updated to title '" << newTitle << "' and new teacher ID: " << newTeacherId << std::endl;
    return true;
}

bool CourseManagementService::removeCourse(const std::string& courseId) {
    auto course = courseRepository->getCourseById(courseId);
    if (!course) {
        std::cerr << "Error: Course with ID " << courseId << " not found for removal." << std::endl;
        return false;
    }
    courseRepository->deleteCourse(courseId);
    std::cout << "Course " << courseId << " removed." << std::endl;
    return true;
}

std::vector<std::shared_ptr<Course>> CourseManagementService::getCoursesTaughtBy(const std::string& teacherId) const {
    return courseRepository->getCoursesByTeacherId(teacherId);
}

std::shared_ptr<Course> CourseManagementService::getCourseDetails(const std::string& courseId) const {
    return courseRepository->getCourseById(courseId);
}

std::vector<std::shared_ptr<Course>> CourseManagementService::getAllAvailableCourses() const {
    return courseRepository->getAllCourses();
}
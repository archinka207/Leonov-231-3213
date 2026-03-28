// --- ВАЖНО: Убедитесь, что CourseRepository.h выше содержит корректное объявление класса CourseRepository ---
#include "CourseRepository.h" // Этот заголовочный файл ОБЯЗАТЕЛЕН и должен быть первым!

// Дополнительные стандартные заголовки, если CourseRepository.h их не включил
#include <algorithm> // Для std::remove_if
#include <iostream>  // Для std::cerr, std::endl
// <memory>, <string>, <vector> теперь включаются в CourseRepository.h,
// поэтому здесь они не строго обязательны, но можно оставить для самодостаточности.

// Параметр изменен с 'courses' на 'course' для предотвращения путаницы с полем класса
void CourseRepository::addCourse(std::shared_ptr<Course> course) {
    if (!course) {
        std::cerr << "Error: Attempted to add a null course." << std::endl;
        return;
    }
    this->courses.push_back(course); // Использование 'this->' для явного обращения к члену класса
}

std::shared_ptr<Course> CourseRepository::getCourseById(const std::string& id) const { // Добавлен const
    for (const auto& course : this->courses) { // Использование 'this->'
        if (course->getId() == id) {
            return course;
        }
    }
    return nullptr;
}

std::vector<std::shared_ptr<Course>> CourseRepository::getAllCourses() const {
    return this->courses; // Использование 'this->'
}

void CourseRepository::updateCourse(std::shared_ptr<Course> updatedCourse) {
    if (!updatedCourse) {
        std::cerr << "Error: Attempted to update with a null course object." << std::endl;
        return;
    }
    for (auto& course : this->courses) { // Использование 'this->'
        if (course->getId() == updatedCourse->getId()) {
            course->setTitle(updatedCourse->getTitle());
            course->setTeacherId(updatedCourse->getTeacherId());
            return;
        }
    }
    std::cerr << "Warning: Course with ID " << updatedCourse->getId() << " not found for update." << std::endl;
}

void CourseRepository::deleteCourse(const std::string& id) {
    // Использование 'this->' для явного обращения к члену класса
    auto it = std::remove_if(this->courses.begin(), this->courses.end(),
                             [&id](const std::shared_ptr<Course>& course) {
                                 return course->getId() == id;
                             });
    if (it != this->courses.end()) { // Использование 'this->'
        this->courses.erase(it, this->courses.end()); // Использование 'this->'
    } else {
        std::cerr << "Warning: Course with ID " << id << " not found for deletion." << std::endl;
    }
}

std::vector<std::shared_ptr<Course>> CourseRepository::getCoursesByTeacherId(const std::string& teacherId) const {
    std::vector<std::shared_ptr<Course>> teacherCourses;
    for (const auto& course : this->courses) { // Использование 'this->'
        if (course->getTeacherId() == teacherId) {
            teacherCourses.push_back(course);
        }
    }
    return teacherCourses;
}
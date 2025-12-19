#include <iostream>
#include <string>
#include <vector>
#include <memory>   // Явно для std::shared_ptr

// Включаем все необходимые .h файлы
#include "IdGenerator.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Enrollment.h"

#include "StudentRepository.h"
#include "TeacherRepository.h"
#include "CourseRepository.h"
#include "EnrollmentRepository.h"

#include "CourseManagementService.h"
#include "EnrollmentService.h"
#include <optional> // Для std::optional в printEnrollmentDetails

void printStudentDetails(std::shared_ptr<Student> student) {
    if (student) {
        std::cout << "  Student ID: " << student->getId() << ", Name: " << student->getName() << std::endl;
    } else {
        std::cout << "  Student not found." << std::endl;
    }
}

void printCourseDetails(std::shared_ptr<Course> course) {
    if (course) {
        std::cout << "  Course ID: " << course->getId() << ", Title: " << course->getTitle()
                  << ", Teacher ID: " << course->getTeacherId() << std::endl;
    } else {
        std::cout << "  Course not found." << std::endl;
    }
}

void printEnrollmentDetails(std::shared_ptr<Enrollment> enrollment) {
    if (enrollment) {
        std::cout << "  Enrollment ID: " << enrollment->getId()
                  << ", Student ID: " << enrollment->getStudentId()
                  << ", Course ID: " << enrollment->getCourseId();
        if (enrollment->getGrade().has_value()) { // Используйте has_value() для проверки
            std::cout << ", Grade: " << enrollment->getGrade().value();
        } else {
            std::cout << ", Grade: N/A";
        }
        std::cout << std::endl;
    } else {
        std::cout << "  Enrollment not found." << std::endl;
    }
}

int main() {
    // Инициализация репозиториев
    auto studentRepo = std::make_shared<StudentRepository>();
    auto teacherRepo = std::make_shared<TeacherRepository>();
    auto courseRepo = std::make_shared<CourseRepository>();
    auto enrollmentRepo = std::make_shared<EnrollmentRepository>();

    // Инициализация сервисов
    auto courseManagementService = std::make_shared<CourseManagementService>(courseRepo, teacherRepo);
    auto enrollmentService = std::make_shared<EnrollmentService>(enrollmentRepo, studentRepo, courseRepo);

    std::cout << "--- Система Факультатив: Демонстрация ---" << std::endl;

    // 1. Создание преподавателей
    std::cout << "\n1. Создание преподавателей:" << std::endl;
    auto teacher1 = std::make_shared<Teacher>("Иванов И.И.", IdGenerator::generateId());
    auto teacher2 = std::make_shared<Teacher>("Петрова А.С.", IdGenerator::generateId());
    teacherRepo->addTeacher(teacher1);
    teacherRepo->addTeacher(teacher2);
    std::cout << "  Преподаватель: " << teacher1->getName() << " (ID: " << teacher1->getId() << ")" << std::endl;
    std::cout << "  Преподаватель: " << teacher2->getName() << " (ID: " << teacher2->getId() << ")" << std::endl;

    // 2. Создание студентов
    std::cout << "\n2. Создание студентов:" << std::endl;
    auto student1 = std::make_shared<Student>("Сидоров А.В.", IdGenerator::generateId());
    auto student2 = std::make_shared<Student>("Козлова Е.М.", IdGenerator::generateId());
    auto student3 = std::make_shared<Student>("Михайлов П.Д.", IdGenerator::generateId());
    studentRepo->addStudent(student1);
    studentRepo->addStudent(student2);
    studentRepo->addStudent(student3);
    std::cout << "  Студент: " << student1->getName() << " (ID: " << student1->getId() << ")" << std::endl;
    std::cout << "  Студент: " << student2->getName() << " (ID: " << student2->getId() << ")" << std::endl;
    std::cout << "  Студент: " << student3->getName() << " (ID: " << student3->getId() << ")" << std::endl;

    // 3. Преподаватель объявляет курсы
    std::cout << "\n3. Преподаватель объявляет курсы:" << std::endl;
    auto course1 = courseManagementService->createCourse("Основы C++", teacher1->getId());
    auto course2 = courseManagementService->createCourse("Алгоритмы и структуры данных", teacher1->getId());
    auto course3 = courseManagementService->createCourse("Базы данных", teacher2->getId());

    // 4. Студенты записываются на курсы
    std::cout << "\n4. Студенты записываются на курсы:" << std::endl;
    enrollmentService->enrollStudent(student1->getId(), course1->getId());
    enrollmentService->enrollStudent(student2->getId(), course1->getId());
    enrollmentService->enrollStudent(student3->getId(), course1->getId());
    enrollmentService->enrollStudent(student1->getId(), course2->getId());
    enrollmentService->enrollStudent(student2->getId(), course3->getId());
    // Попытка записать студента повторно (должно быть предупреждение)
    enrollmentService->enrollStudent(student1->getId(), course1->getId());
    // 5. Преподаватель выставляет оценки
    std::cout << "\n5. Преподаватель выставляет оценки:" << std::endl;
    if (auto e1 = enrollmentRepo->getEnrollmentByStudentAndCourse(student1->getId(), course1->getId())) {
        enrollmentService->assignGrade(e1->getId(), 90);
    }
    if (auto e2 = enrollmentRepo->getEnrollmentByStudentAndCourse(student2->getId(), course1->getId())) {
        enrollmentService->assignGrade(e2->getId(), 75);
    }
    if (auto e3 = enrollmentRepo->getEnrollmentByStudentAndCourse(student3->getId(), course1->getId())) {
        enrollmentService->assignGrade(e3->getId(), 88);
    }
    if (auto e4 = enrollmentRepo->getEnrollmentByStudentAndCourse(student1->getId(), course2->getId())) {
        enrollmentService->assignGrade(e4->getId(), 95);
    }
    if (auto e5 = enrollmentRepo->getEnrollmentByStudentAndCourse(student2->getId(), course3->getId())) {
        enrollmentService->assignGrade(e5->getId(), 80);
    }


    // 6. Просмотр записей студента
    std::cout << "\n6. Записи студента " << student1->getName() << ":" << std::endl;
    auto s1Enrollments = enrollmentService->getStudentEnrollments(student1->getId());
    for (const auto& enr : s1Enrollments) {
        printEnrollmentDetails(enr);
    }

    // 7. Просмотр студентов на курсе
    std::cout << "\n7. Студенты на курсе '" << course1->getTitle() << "':" << std::endl;
    auto studentsInCourse1 = enrollmentService->getStudentsInCourse(course1->getId());
    for (const auto& stud : studentsInCourse1) {
        printStudentDetails(stud);
    }
    
    // 8. Просмотр курсов, которые ведет преподаватель
    std::cout << "\n8. Курсы, которые ведет преподаватель " << teacher1->getName() << ":" << std::endl;
    auto teacher1Courses = courseManagementService->getCoursesTaughtBy(teacher1->getId());
    for (const auto& course : teacher1Courses) {
        printCourseDetails(course);
    }

    // 9. Просмотр Архива (всех записей с оценками)
    std::cout << "\n9. Полный Архив Записей:" << std::endl;
    auto archive = enrollmentService->getArchive();
    for (const auto& enr : archive) {
        printEnrollmentDetails(enr);
    }

    // 10. Демонстрация OCP: Добавление новой функциональности (например, получение всех студентов)
    std::cout << "\n10. Список всех студентов (демонстрация OCP):" << std::endl;
    for (const auto& student : studentRepo->getAllStudents()) {
        printStudentDetails(student);
    }

    std::cout << "\n--- Демонстрация завершена ---" << std::endl;

    return 0;
}
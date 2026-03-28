#include <iostream>
#include "student.h"
#include "teacher.h"
#include "head_of_department.h"
#include "lecture_hall.h"

int main() {
    // 1. Создание объектов
    Student s1("Иван Иванов");
    Student s2("Петр Петров");
    Teacher t1("Александр Сергеевич");
    HeadOfDepartment h1("Виктор Михайлович");

    std::cout << "=== ТЕСТ 1: Обычная лекция (Teacher + Students) ===" << std::endl;
    
    // DIP: LectureHall принимает интерфейс ITeacher
    LectureHall physicsLesson(&t1);
    physicsLesson.addStudent(&s1);
    physicsLesson.addStudent(&s2);
    
    physicsLesson.startLesson();

    std::cout << "=== ТЕСТ 2: Демонстрация LSP (HeadOfDepartment вместо Teacher) ===" << std::endl;
    
    // LSP: Мы передаем Заведующего туда, где ожидается Преподаватель.
    // Класс LectureHall не менялся, но поведение изменилось корректно.
    LectureHall masterClass(&h1);
    masterClass.addStudent(&s1); // Тот же студент
    
    masterClass.startLesson();

    std::cout << "=== ТЕСТ 3: Демонстрация ISP (Специфичные методы) ===" << std::endl;
    
    // s1.teach();    // Ошибка компиляции! Студент не имеет метода teach.
    // t1.manage();   // Ошибка компиляции! Преподаватель не имеет метода manage.
    
    std::cout << "Только Заведующий имеет доступ к управлению:" << std::endl;
    h1.manage(); // Работает, так как реализует IManager

    return 0;
}
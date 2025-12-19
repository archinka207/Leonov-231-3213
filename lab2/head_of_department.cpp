#include "head_of_department.h"

HeadOfDepartment::HeadOfDepartment(const std::string& name) : Person(name) {}

void HeadOfDepartment::teach() const {
    std::cout << "[Зав. Кафедрой] " << name << " проводит важную лекцию на основе своего опыта." << std::endl;
}

void HeadOfDepartment::manage() const {
    std::cout << "[Зав. Кафедрой] " << name << " составляет расписание и проверяет ведомости." << std::endl;
}

std::string HeadOfDepartment::getName() const {
    return Person::getName();
}
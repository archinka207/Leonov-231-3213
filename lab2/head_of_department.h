#ifndef HEAD_OF_DEPARTMENT_H
#define HEAD_OF_DEPARTMENT_H

#include "person.h"
#include "interfaces.h"

class HeadOfDepartment : public Person, public ITeacher, public IManager {
public:
    HeadOfDepartment(const std::string& name);

    // Реализация ITeacher (LSP - может заменить учителя)
    void teach() const override;
    
    // Реализация IManager (ISP - отдельный интерфейс)
    void manage() const override;

    std::string getName() const override;
};

#endif
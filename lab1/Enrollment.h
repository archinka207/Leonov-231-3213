#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>
#include <optional> // Для хранения оценки, которая может отсутствовать

class Enrollment {
public:
    Enrollment(const std::string& studentId, const std::string& courseId, const std::string& id);

    const std::string& getId() const;
    const std::string& getStudentId() const;
    const std::string& getCourseId() const;
    std::optional<int> getGrade() const;
    void setGrade(int grade);

private:
    std::string id;
    std::string studentId;
    std::string courseId;
    std::optional<int> grade; // Оценка, может быть не выставлена
};

#endif // ENROLLMENT_H
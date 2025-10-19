#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course {
public:
    Course(const std::string& title, const std::string& teacherId, const std::string& id);

    const std::string& getId() const;
    const std::string& getTitle() const;
    void setTitle(const std::string& title);
    const std::string& getTeacherId() const;
    void setTeacherId(const std::string& teacherId);

private:
    std::string id;
    std::string title;
    std::string teacherId; // ID преподавателя, который ведет курс
};

#endif // COURSE_H
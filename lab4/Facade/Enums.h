#ifndef ENUMS_H
#define ENUMS_H

enum class Gender {
    MALE,
    FEMALE
};

enum class ActivityLevel {
    LOW,    // Сидячий образ жизни
    MEDIUM, // Тренировки 3-5 раз в неделю
    HIGH    // Интенсивные нагрузки
};

enum class BodyTypeEnum {
    ASTHENIC,     // Худощавый
    NORMOSTHENIC, // Атлетичный/Средний
    HYPERSTHENIC  // Широкая кость/Склонность к полноте
};

struct PersonData {
    double weight; // кг
    double height; // см
    int age;       // лет
    Gender gender;
};

#endif
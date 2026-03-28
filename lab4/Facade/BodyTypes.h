#ifndef BODYTYPES_H
#define BODYTYPES_H

#include <string>

// Абстрактный базовый класс
class IBodyType {
public:
    virtual ~IBodyType() = default;
    // Корректировка метаболизма: >1 ускоренный, <1 замедленный
    virtual double getMetabolicCorrection() const = 0;
    virtual std::string getName() const = 0;
};

// Астеник: быстрый метаболизм, требуется больше калорий
class Asthenic : public IBodyType {
public:
    double getMetabolicCorrection() const override {
        return 1.10; // +10% к норме
    }
    std::string getName() const override {
        return "Asthenic";
    }
};

// Нормостеник: стандартный метаболизм
class Normosthenic : public IBodyType {
public:
    double getMetabolicCorrection() const override {
        return 1.0; // Норма
    }
    std::string getName() const override {
        return "Normosthenic";
    }
};

// Гиперстеник: медленный метаболизм, требуется меньше калорий
class Hypersthenic : public IBodyType {
public:
    double getMetabolicCorrection() const override {
        return 0.95; // -5% от нормы
    }
    std::string getName() const override {
        return "Hypersthenic";
    }
};

#endif
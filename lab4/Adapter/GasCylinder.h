#ifndef GASCYLINDER_H
#define GASCYLINDER_H

#include <string>

// Адаптируемый класс: Баллон с газом
class GasCylinder {
protected: // protected чтобы наследник (Адаптер) имел доступ к полям
    double Volume;  // м3
    double Mass;    // кг
    double Molar;   // кг/моль
    const double R = 8.31; // Универсальная газовая постоянная

public:
    GasCylinder(double v, double m, double mol);
    virtual ~GasCylinder() = default;

    // Определить давление при заданной температуре T (Кельвины)
    double GetPressure(int T) const;

    // Определить количество вещества (моль)
    double AmountOfMatter() const;

    // Строковое представление
    std::string ToString() const;
};

#endif
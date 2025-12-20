#ifndef IGASSYSTEM_H
#define IGASSYSTEM_H

#include <string>

// Требуемый интерфейс (Target)
class IGasSystem {
public:
    virtual ~IGasSystem() = default;

    // Изменить объём баллона на величину dV
    virtual void ModifVolume(double dV) = 0;

    // Определить изменение давления при изменении температуры с T0 до T1
    virtual double GetDp(int T0, int T1) = 0;

    // Возвращает строку с данными об объекте (новый формат)
    virtual std::string Passport() = 0;
};

#endif
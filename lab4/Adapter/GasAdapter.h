#ifndef GASADAPTER_H
#define GASADAPTER_H

#include "IGasSystem.h"
#include "GasCylinder.h"

// Адаптер класса (наследует интерфейс публично, реализацию приватно)
class GasAdapter : public IGasSystem, private GasCylinder {
public:
    GasAdapter(double v, double m, double mol);

    // Реализация методов интерфейса IGasSystem
    
    void ModifVolume(double dV) override;
    
    double GetDp(int T0, int T1) override;
    
    std::string Passport() override;
};

#endif
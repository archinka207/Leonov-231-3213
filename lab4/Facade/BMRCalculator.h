#ifndef BMRCALCULATOR_H
#define BMRCALCULATOR_H

#include "Enums.h"

class BMRCalculator {
public:
    double calculateBMR(const PersonData& data) {
        // Формула: 10 * вес + 6.25 * рост - 5 * возраст + S
        // S = +5 для мужчин, -161 для женщин
        double base = (10.0 * data.weight) + (6.25 * data.height) - (5.0 * data.age);
        
        if (data.gender == Gender::MALE) {
            return base + 5.0;
        } else {
            return base - 161.0;
        }
    }
};

#endif
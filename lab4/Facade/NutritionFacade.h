#ifndef NUTRITIONFACADE_H
#define NUTRITIONFACADE_H

#include "Enums.h"
#include "BodyTypes.h"
#include "BMRCalculator.h"
#include <memory>
#include <iostream>

class NutritionFacade {
private:
    BMRCalculator calculator;

    // Фабричный метод для создания объекта типа телосложения
    std::unique_ptr<IBodyType> createBodyType(BodyTypeEnum type) {
        switch (type) {
            case BodyTypeEnum::ASTHENIC:
                return std::make_unique<Asthenic>();
            case BodyTypeEnum::NORMOSTHENIC:
                return std::make_unique<Normosthenic>();
            case BodyTypeEnum::HYPERSTHENIC:
                return std::make_unique<Hypersthenic>();
            default:
                return std::make_unique<Normosthenic>();
        }
    }

    double getActivityCoefficient(ActivityLevel level) {
        switch (level) {
            case ActivityLevel::LOW: return 1.2;
            case ActivityLevel::MEDIUM: return 1.55;
            case ActivityLevel::HIGH: return 1.9;
            default: return 1.2;
        }
    }

public:
    // Главный метод фасада
    double calculateDailyCalories(const PersonData& data, ActivityLevel activity, BodyTypeEnum bodyTypeEnum) {
        // 1. Расчет базового обмена (BMR)
        double bmr = calculator.calculateBMR(data);

        // 2. Получение объекта телосложения и его коэффициента
        auto bodyTypeObj = createBodyType(bodyTypeEnum);
        double bodyMod = bodyTypeObj->getMetabolicCorrection();

        // 3. Получение коэффициента активности
        double activityMod = getActivityCoefficient(activity);

        // Логирование процесса (для демонстрации тестирования)
        std::cout << "  [Logic] BMR: " << bmr 
                  << " | Activity: x" << activityMod 
                  << " | Type (" << bodyTypeObj->getName() << "): x" << bodyMod << std::endl;

        // Итоговая формула
        return bmr * activityMod * bodyMod;
    }
};

#endif
#include <iostream>
#include <vector>
#include "NutritionFacade.h"
#include "Enums.h"

void runTest(const std::string& testName, PersonData p, ActivityLevel act, BodyTypeEnum type) {
    std::cout << "------------------------------------------------" << std::endl;
    std::cout << "TEST: " << testName << std::endl;
    std::cout << "Input: Weight=" << p.weight << "kg, Height=" << p.height 
              << "cm, Age=" << p.age << ", Gender=" << (p.gender == Gender::MALE ? "M" : "F") << std::endl;
    
    NutritionFacade facade;
    double result = facade.calculateDailyCalories(p, act, type);
    
    std::cout << ">>> Recommended Daily Intake: " << result << " kcal" << std::endl;
    std::cout << "------------------------------------------------" << std::endl;
}

int main() {
    std::cout << "=== Calorie Calculator Facade Pattern Test ===\n" << std::endl;

    // Тест 1: Мужчина, Астеник (должен быть высокий калораж из-за метаболизма)
    PersonData p1 = {75.0, 180.0, 25, Gender::MALE};
    runTest("Male Asthenic High Activity", p1, ActivityLevel::HIGH, BodyTypeEnum::ASTHENIC);

    // Тест 2: Женщина, Гиперстеник (должен быть пониженный калораж)
    PersonData p2 = {65.0, 165.0, 30, Gender::FEMALE};
    runTest("Female Hypersthenic Low Activity", p2, ActivityLevel::LOW, BodyTypeEnum::HYPERSTHENIC);

    // Тест 3: Мужчина, Нормостеник (стандарт)
    PersonData p3 = {80.0, 178.0, 40, Gender::MALE};
    runTest("Male Normosthenic Medium Activity", p3, ActivityLevel::MEDIUM, BodyTypeEnum::NORMOSTHENIC);

    return 0;
}
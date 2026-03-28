#include <iostream>
#include <cassert>
#include "GasAdapter.h"

void TestGasSystem() {
    std::cout << "Starting functionality tests..." << std::endl;

    // Параметры для Азота (N2): M = 0.028 кг/моль
    // V = 1.0 м3, m = 1.0 кг
    GasAdapter* adapter = new GasAdapter(1.0, 1.0, 0.028);

    // 1. Тест Passport (и косвенно ToString)
    std::cout << adapter->Passport() << std::endl;

    // 2. Тест изменения давления (GetDp)
    // T0 = 300K, T1 = 310K
    // P = (m/M)*(R/V)*T
    // const K = (1/0.028)*(8.31/1) = 296.7857
    // P(300) = 89035.7, P(310) = 92003.5
    // DP ≈ 2967.8
    double dp = adapter->GetDp(300, 310);
    std::cout << "Delta P (300K -> 310K): " << dp << " Pa" << std::endl;
    
    // Простейшая проверка (разница должна быть положительной при нагреве)
    if (dp > 0) std::cout << "[OK] Pressure increased with temperature." << std::endl;
    else std::cout << "[FAIL] Pressure logic error." << std::endl;

    // 3. Тест изменения объема (ModifVolume)
    // Уменьшаем объем в 2 раза (сжатие), давление должно вырасти при той же T
    double p_before = adapter->GetDp(0, 300); // Получаем P при 300 (т.к. P(0)=0)
    
    adapter->ModifVolume(-0.5); // Теперь объем 0.5
    std::cout << "Volume decreased by 0.5 m3." << std::endl;
    std::cout << adapter->Passport() << std::endl;

    double p_after = adapter->GetDp(0, 300);
    
    std::cout << "P before: " << p_before << ", P after: " << p_after << std::endl;
    
    if (p_after > p_before) std::cout << "[OK] Pressure increased after volume reduction." << std::endl;
    else std::cout << "[FAIL] Volume modification logic error." << std::endl;

    delete adapter;
    std::cout << "Tests finished." << std::endl;
}

int main() {
    TestGasSystem();
    return 0;
}
#include "GasAdapter.h"
#include <sstream>
#include <cmath>

GasAdapter::GasAdapter(double v, double m, double mol) 
    : GasCylinder(v, m, mol) {}

void GasAdapter::ModifVolume(double dV) {
    // Адаптер имеет доступ к Volume, так как он protected в GasCylinder
    this->Volume += dV;
    if (this->Volume < 0) this->Volume = 0;
}

double GasAdapter::GetDp(int T0, int T1) {
    // Используем функциональность родительского класса GasCylinder
    double p0 = GetPressure(T0);
    double p1 = GetPressure(T1);
    return p1 - p0;
}

std::string GasAdapter::Passport() {
    std::stringstream ss;
    ss << "--- SYSTEM PASSPORT ---\n";
    // Вызов метода родителя
    ss << GasCylinder::ToString() << "\n";
    ss << "Matter Amount: " << AmountOfMatter() << " mol\n";
    ss << "-----------------------";
    return ss.str();
}
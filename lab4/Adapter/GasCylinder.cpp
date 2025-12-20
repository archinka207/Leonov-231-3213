#include "GasCylinder.h"
#include <sstream>
#include <iomanip>

GasCylinder::GasCylinder(double v, double m, double mol) 
    : Volume(v), Mass(m), Molar(mol) {}

double GasCylinder::GetPressure(int T) const {
    if (Volume <= 0 || Molar <= 0) return 0.0;
    // PV = (m/M)RT  => P = (m * R * T) / (M * V)
    return (Mass * R * T) / (Molar * Volume);
}

double GasCylinder::AmountOfMatter() const {
    if (Molar <= 0) return 0.0;
    return Mass / Molar;
}

std::string GasCylinder::ToString() const {
    std::stringstream ss;
    ss << "GasCylinder [V=" << Volume << " m3, Mass=" << Mass 
       << " kg, Molar=" << Molar << " kg/mol]";
    return ss.str();
}
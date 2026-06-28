#include "Mobility.hpp"

int Mobility(int mobility, double bloodcode_weight, double weapon_weight, double blood_veil_weight)
{
    double ratio = (weapon_weight + blood_veil_weight) / bloodcode_weight;
    if (ratio > 1.35) mobility -= 2;
    else if (ratio > 1.0) mobility -= 1;
    else if (ratio > 0.5) return mobility;
    else if (ratio > 0.2) mobility += 1;
    else mobility += 2;
    if (mobility < 2) return 1;
    else if (mobility > 2) return 3;
    return 2;
}
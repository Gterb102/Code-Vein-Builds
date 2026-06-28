#ifndef PHYSICAL_DAMAGE_HPP
#define PHYSICAL_DAMAGE_HPP

#include <cmath>

double WeaponBaseDamage(int, int);
double f_stat(int, int, int, int);
double StatScaling(int, int, int, int, int, int);
double PhysicalDamage(int, double, int, int, int, int, int, int, int);

#endif
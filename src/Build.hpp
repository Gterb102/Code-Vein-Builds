#ifndef BUILD_HPP
#define BUILD_HPP

#include <string>

struct Build {
    std::string Blood_code;
    std::string Weapon;
    std::string Blood_veil;
    int Level;
    int Weapon_reinforcement;
    int Blood_veil_reinforcement;
    int Str_boosts;
    int Dex_boosts;
    int Mind_boosts;
    int Wil_boosts;
    double Physical_damage;
    std::string Mobility;
    std::string Weapon_type;
};

#endif
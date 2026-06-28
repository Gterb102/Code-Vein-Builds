#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

struct Weapon {
    std::string name;
    double bpd;
    double wt;
    int ss_str;
    int ss_dex;
    int ss_mnd;
    int ss_wil;
    int rs_str;
    int rs_dex;
    int rs_mnd;
    int rs_wil;
};

#endif
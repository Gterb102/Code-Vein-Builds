#include "Physical_Damage.hpp"

double WeaponBaseDamage(double B, int WR) {return (1 + 0.1 * WR) * B;}

double f_stat(int level, int bc_stat, int w_stat, int n_stat) {
    double bc_q = pow(bc_stat + n_stat / level, 2);
    double level_q = pow(level, 2);
    return bc_q * level_q * pow(w_stat, 2) / ((bc_q * level_q + 1000000) * 100);
}

double StatScaling(int bc_str, int bc_dex, int w_str, int w_dex, int n_str, int n_dex) {
    return (pow(bc_dex + n_dex, 2) * pow(w_dex, 2) + pow(bc_str + n_str, 2) * pow(w_str, 2)) / 50000;
}

double PhysicalDamage(int level, double B, int WR, int bc_str, int bc_dex, int w_str, int w_dex, int n_str, int n_dex) {
    int PD;
    double M;
    double WBD = WeaponBaseDamage(B, WR);
    double f_str = f_stat(level, bc_str, w_str, n_str);
    double f_dex = f_stat(level, bc_dex, w_dex, n_dex);
    double SS = StatScaling(bc_str, bc_dex, w_str, w_dex, n_str, n_dex);
    M = f_str + f_dex + SS;
    PD = WBD + WBD * M;
    return PD;
}
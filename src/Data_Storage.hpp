#ifndef DATA_STORAGE_HPP
#define DATA_STORAGE_HPP

#include <vector>
#include <string>
#include <fstream>
#include "Decoder.hpp"
#include "Blood_Code.hpp"
#include "Weapon.hpp"
#include "Blood_Veil.hpp"

class DataStorage
{

private:

    std::string blood_codes_path;
    std::string weapons_path;
    std::string blood_veil_path;
    std::vector<BloodCode> Blood_codes;
    std::vector<Weapon> One_handed_swords;
    std::vector<Weapon> Two_handed_swords;
    std::vector<Weapon> Halberds;
    std::vector<Weapon> Hammers;
    std::vector<Weapon> Bayonets;
    std::vector<BloodVeil> Blood_veils;

public:

    DataStorage(const std::string path);
    std::vector<BloodCode>& BloodCodeGetter();
    std::vector<Weapon>& OneHandedSwordGetter();
    std::vector<Weapon>& TwoHandedSwordGetter();
    std::vector<Weapon>& HalberdGetter();
    std::vector<Weapon>& HammerGetter();
    std::vector<Weapon>& BayonetGetter();
    std::vector<BloodVeil>& BloodVeilGetter();
    void LoadFromFile(const std::string blood_codes_path, const std::string weapons_path, const std::string blood_veil_path);

};

#endif
#ifndef SETTING_LIST_HPP
#define SETTING_LIST_HPP

#include <string>
#include <fstream>

class SettingList
{

private:

    std::string settings_path;
    int blood_code;
    int weapon_type;
    int mobility;
    int level;
    int weapon_reinforcement;
    int blood_veil_reinforcement;
    int str_boosts;
    int dex_boosts;
    int mnd_boosts;
    int wil_boosts;

public:

    SettingList(std::string);
    std::string& SettingsPathGetter();

    int BloodCodeGetter();
    int WeaponTypeGetter();
    int MobilityGetter();
    int LevelGetter();
    int WeaponReinforcementGetter();
    int BloodVeilReinforcementGetter();
    int StrBoostsGetter();
    int DexBoostsGetter();
    int MndBoostsGetter();
    int WilBoostsGetter();

    void BloodCodeSetter(int);
    void WeaponTypeSetter(int);
    void MobilitySetter(int);
    void LevelSetter(int);
    void WeaponReinforcementSetter(int);
    void BloodVeilReinforcementSetter(int);
    void StrBoostsSetter(int);
    void DexBoostsSetter(int);
    void MndBoostsSetter(int);
    void WilBoostsSetter(int);

    void SaveSettings();
    void LoadSettings();

};

#endif
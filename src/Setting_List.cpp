#include "Setting_List.hpp"

SettingList::SettingList(std::string path)
{
    path.erase(path.length() - 19);
    settings_path = path + "\\data\\Settings.txt";

    LoadSettings();
}

std::string& SettingList::SettingsPathGetter() {return settings_path;}
int SettingList::BloodCodeGetter() {return blood_code;}
int SettingList::WeaponTypeGetter() {return weapon_type;}
int SettingList::MobilityGetter() {return mobility;}
int SettingList::LevelGetter() {return level;}
int SettingList::WeaponReinforcementGetter() {return weapon_reinforcement;}
int SettingList::BloodVeilReinforcementGetter() {return blood_veil_reinforcement;}
int SettingList::StrBoostsGetter() {return str_boosts;}
int SettingList::DexBoostsGetter() {return dex_boosts;}
int SettingList::MndBoostsGetter() {return mnd_boosts;}
int SettingList::WilBoostsGetter() {return wil_boosts;}

void SettingList::BloodCodeSetter(int n) {blood_code = n;}
void SettingList::WeaponTypeSetter(int n) {weapon_type = n;}
void SettingList::MobilitySetter(int n) {mobility = n;}
void SettingList::LevelSetter(int n) {level = n;}
void SettingList::WeaponReinforcementSetter(int n) {weapon_reinforcement = n;}
void SettingList::BloodVeilReinforcementSetter(int n) {blood_veil_reinforcement = n;}
void SettingList::StrBoostsSetter(int n) {str_boosts = n;}
void SettingList::DexBoostsSetter(int n) {dex_boosts = n;}
void SettingList::MndBoostsSetter(int n) {mnd_boosts = n;}
void SettingList::WilBoostsSetter(int n) {wil_boosts = n;}

void SettingList::SaveSettings()
{
    std::ofstream fout(settings_path, std::ios::out);
    if (!fout) throw "Error: Problem with save Settings file!\n\n";

    fout << "--- Settings ---\n";
    fout << "\nBlood Code: " << blood_code;
    fout << "\nWeapon Type: " << weapon_type;
    fout << "\nMobility: " << mobility;
    fout << "\nLevel: " << level;
    fout << "\nWeapon Reinforcement: " << weapon_reinforcement;
    fout << "\nBlood Veil Reinforcement: " << blood_veil_reinforcement;
    fout << "\nStrength Boosts: " << str_boosts;
    fout << "\nDexterity Boosts: " << dex_boosts;
    fout << "\nMind Boosts: " << mnd_boosts;
    fout << "\nWillpower Boosts: " << wil_boosts;
    fout << "\n\n--- End File ---";

    fout.close();
}

void SettingList::LoadSettings()
{
    std::ifstream fin(settings_path, std::ios::in);
    if (!fin) throw "Error: Problem with load Settings file!\n\n";

    std::string buf;

    std::getline(fin, buf);
    if (buf != "--- Settings ---") throw "Error: Settings file may be corrupted!";
    std::getline(fin, buf);

    std::getline(fin, buf);
    buf.erase(0, 12);
    blood_code = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 13);
    weapon_type = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 10);
    mobility = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 7);
    level = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 22);
    weapon_reinforcement = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 26);
    blood_veil_reinforcement = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 17);
    str_boosts = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 18);
    dex_boosts = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 13);
    mnd_boosts = stoi(buf);

    std::getline(fin, buf);
    buf.erase(0, 18);
    wil_boosts = stoi(buf);

    std::getline(fin, buf);
    std::getline(fin, buf);
    if (buf != "--- End File ---") throw "Error: Settings file may be corrupted!";

    fin.close();
}
#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Data_Storage.hpp"
#include "Build_List.hpp"
#include "Input_Handling.hpp"
#include "Display.hpp"
#include "Setting_List.hpp"
#include "Cursor_Switch.hpp"
#include <iostream>
#include <stdexcept>
#include <cstdlib>

void MainMenu(const std::string);
BuildList* GenerateBuilds(BuildList*, DataStorage&, SettingList&, std::string);
void HowManyDisplayResultMenu(BuildList*);
void SettingMenu(SettingList&, DataStorage&);
void BloodCodeSettingMenu(SettingList&, DataStorage&);
void WeaponTypeSettingMenu(SettingList&);
void MobilitySettingMenu(SettingList&);
void LevelSettingMenu(SettingList&);
void WeaponReinforcementSettingMenu(SettingList&);
void BloodVeilReinforcementSettingMenu(SettingList&);
void StrBoostsSettingMenu(SettingList&);
void DexBoostsSettingMenu(SettingList&);
void MndBoostsSettingMenu(SettingList&);
void WilBoostsSettingMenu(SettingList&);

#endif
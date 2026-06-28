#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include "Setting_List.hpp"
#include "Data_Storage.hpp"
#include "Decoder.hpp"
#include <iostream>

void DisplayMainMenu();
void DisplayIsDisplayResultMenu();
void DisplayHowManyDisplayResultMenu(int);
void DisplaySettingMenu(SettingList&, DataStorage&, int);
void DisplayBloodCodeSettingMenu(DataStorage&, int);
void DisplayWeaponTypeSettingMenu();
void DisplayMobilitySettingMenu();
void DisplayLevelSettingMenu();
void DisplayWeaponReinforcementSettingMenu();
void DisplayBloodVeilReinforcementSettingMenu();
void DisplayStrBoostsSettingMenu();
void DisplayDexBoostsSettingMenu();
void DisplayMndBoostsSettingMenu();
void DisplayWilBoostsSettingMenu();

#endif
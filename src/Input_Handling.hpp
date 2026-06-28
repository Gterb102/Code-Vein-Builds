#ifndef INPUT_HANDLING_HPP
#define INPUT_HANDLING_HPP

#include "Setting_List.hpp"
#include "Data_Storage.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <conio.h>

void InputAnyButton();
int InputButton(void (*Display)());
int InputInteger(void (*Display)());
int InputInteger(void (*Display)(), int, int);
int InputInteger(void (*Display)(int), int, int);
int InputButtonMenu(void (*Display)(SettingList&, DataStorage&, int), SettingList&, DataStorage&, int&);
int InputButtonMenu(void (*Display)(DataStorage&, int), DataStorage&);

#endif
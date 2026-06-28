#include "Display.hpp"

void DisplayMainMenu()
{
    std::cout << "=== CODE VEIN BUILDS ===\n";
    std::cout << "1) Generate builds\n";
    std::cout << "2) Display builds from the latest generation\n";
    std::cout << "3) Generation settings\n";
    std::cout << "0) Exit\n";
}

void DisplayIsDisplayResultMenu()
{
    std::cout << "Would you like to display the results here?\n";
    std::cout << "1) Yes\n";
    std::cout << "0) Exit to Main Menu\n";
}

void DisplayHowManyDisplayResultMenu(int max)
{
    std::cout << "How many results do you want to display here?\n";
    std::cout << "Enter a number from 0 to " << max << "\n";
    std::cout << "Enter value: ";
}

void DisplaySettingMenu(SettingList& Settings, DataStorage& Data, int page)
{
    std::cout << "=== Generation Settings ===\n";
    std::cout << "Select the setting you want to change\n";
    if (page == 1) {
        if (Settings.BloodCodeGetter()) std::cout << "1) Blood Code (" << Data.BloodCodeGetter()[Settings.BloodCodeGetter() - 1].name << ")\n";
        else std::cout << "1) Blood Code (Any)\n";
        std::cout << "2) Weapon Type (" << WeaponTypeDecoderIntToString(Settings.WeaponTypeGetter()) << ")\n";
        std::cout << "3) Mobility (" << MobilityDecoderIntToString(Settings.MobilityGetter()) << ")\n";
        for (int i = 0; i < 6; ++i) std::cout << "\n";
        std::cout << "0) Exit to Main Menu\n";
        std::cout << "   Page 1 ->\n";
    } else {
        std::cout << "1) Level (" << Settings.LevelGetter() << ")\n";
        std::cout << "2) Weapon Reinforcement (" << Settings.WeaponReinforcementGetter() << ")\n";
        std::cout << "3) Blood Veil Reinforcement (" << Settings.BloodVeilReinforcementGetter() << ")\n";
        std::cout << "4) Strength Boosts (" << Settings.StrBoostsGetter() << ")\n";
        std::cout << "5) Dexterity Boosts (" << Settings.DexBoostsGetter() << ")\n";
        std::cout << "6) Mind Boosts (" << Settings.MndBoostsGetter() << ")\n";
        std::cout << "7) Willpower Boosts (" << Settings.WilBoostsGetter() << ")\n";
        for (int i = 0; i < 2; ++i) std::cout << "\n";
        std::cout << "0) Exit to Main Menu\n";
        std::cout << "<- Page 2\n";
    }
    std::cout << "Message: You can use the left and right arrows to navigate to another page\n";
}

void DisplayBloodCodeSettingMenu(DataStorage& Data, int page)
{
    int i = (page - 1) * 9;
    int j = 0;

    std::cout << "What Blood Code should be set?\n";
    if (page == 1) {
        std::cout << "1) Any\n";
        ++j;
    }
    for (; j < 9 && i + j - 1 < Data.BloodCodeGetter().size(); ++j) {
        std::cout << j + 1 << ") " << Data.BloodCodeGetter()[i + j - 1].name << "\n";
    }
    for (; j < 9; ++j) {std::cout << "\n";}
    std::cout << "0) Exit to Setting Menu\n";

    if (page == 1) std::cout << "   Page " << page << " ->\n";
    else if (i + 9 > Data.BloodCodeGetter().size()) std::cout << "<- Page " << page << "   \n";
    else std::cout << "<- Page " << page << " ->\n";
    std::cout << "Message: You can use the left and right arrows to navigate to another page\n";
}

void DisplayWeaponTypeSettingMenu()
{
    std::cout << "What Weapon Type should be set?\n";
    std::cout << "1) Any\n";
    std::cout << "2) One-handed Swords\n";
    std::cout << "3) Two-handed Swords\n";
    std::cout << "4) Halberds\n";
    std::cout << "5) Hammers\n";
    std::cout << "6) Bayonets\n";
    std::cout << "0) Exit to Setting Menu\n";
    std::cout << "Your choice: ";   
}

void DisplayMobilitySettingMenu()
{
    std::cout << "What Mobility should be set?\n";
    std::cout << "1) Any\n";
    std::cout << "2) Slow\n";
    std::cout << "3) Normal\n";
    std::cout << "4) Quick\n";
    std::cout << "0) Exit to Setting Menu\n";
    std::cout << "Your choice: ";   
}

void DisplayLevelSettingMenu()
{
    std::cout << "What Level should be set?\n";
    std::cout << "Enter a number from 1 to 300\n";
    std::cout << "Enter value: ";   
}

void DisplayWeaponReinforcementSettingMenu()
{
    std::cout << "What Weapon Reinforcement should be set?\n";
    std::cout << "Enter a number from 0 to 10\n";
    std::cout << "Enter value: ";
}

void DisplayBloodVeilReinforcementSettingMenu()
{
    std::cout << "What Blood Veil Reinforcement should be set?\n";
    std::cout << "Enter a number from 0 to 10\n";
    std::cout << "Enter value: ";
}

void DisplayStrBoostsSettingMenu()
{
    std::cout << "What Strength Boosts should be set?\n";
    std::cout << "Enter a number from 0 to 10\n";
    std::cout << "Enter value: ";
}

void DisplayDexBoostsSettingMenu()
{
    std::cout << "What Dexterity Boosts should be set?\n";
    std::cout << "Enter a number from 0 to 10\n";
    std::cout << "Enter value: ";
}

void DisplayMndBoostsSettingMenu()
{
    std::cout << "What Mind Boosts should be set?\n";
    std::cout << "Enter a number from 0 to 10\n";
    std::cout << "Enter value: ";
}

void DisplayWilBoostsSettingMenu()
{
    std::cout << "What Willpower Boosts should be set?\n";
    std::cout << "Enter a number from 0 to 10\n";
    std::cout << "Enter value: ";
}
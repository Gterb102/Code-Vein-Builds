#include "Interface.hpp"

void MainMenu(const std::string path)
{
    int choice;

    LoadCursorInfo();
    CursorOff();

    DataStorage Data(path);
    SettingList Settings(path);
    BuildList* Builds = new BuildList(Data, Settings, path);
    if (!Builds) throw "Error: Memory not allocate!";

    Builds->SortBuilds(Builds->BuildsGetter());

    system("cls");

    do
    {
        choice = InputButton(DisplayMainMenu);

        switch(choice)
        {
        case 1:
            system("cls");
            Builds = GenerateBuilds(Builds, Data, Settings, path);
            break;
        case 2:
            system("cls");
            HowManyDisplayResultMenu(Builds);
            break;
        case 3:
            system("cls");
            SettingMenu(Settings, Data);
            break;
        case 0:
            system("cls");
            std::cout << "Exit program\n";
            break;
        default:
            system("cls");
            std::cout << "Message: Wrong choice! Try again\n\n";
        }
    } while (choice != 0);

    Settings.SaveSettings();
    delete Builds;

    CursorOn();
}

BuildList* GenerateBuilds(BuildList* Builds, DataStorage& Data, SettingList& Settings, std::string path)
{
    int choice;
    delete Builds;
    Builds = new BuildList(Data, Settings, path);
    if (!Builds) throw "Error: Memory not allocate!\n\n";

    Builds->SortBuilds(Builds->BuildsGetter());
    Builds->PrintToFile(Builds->BuildsGetter(), Builds->PathFileGetter());
    do
    {
        if (!Builds->BuildsGetter().size()) {
            std::cout << "Message: There are no available builds for the selected settings. Try changing the settings\n";
            InputAnyButton();
            system("cls");
            break;
        }
        std::cout << "Message: The " << Builds->BuildsGetter().size() << " builds were successfully generated. You can view the results in the file Result.txt\n\n";

        choice = InputButton(DisplayIsDisplayResultMenu);

        switch(choice)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            HowManyDisplayResultMenu(Builds);
            break;
        default:
            system("cls");
        }
    } while (choice != 0);

    return Builds;
}

void HowManyDisplayResultMenu(BuildList* Builds)
{
    int number;

    if (!Builds->BuildsGetter().size()) {
        std::cout << "Message: There are no available builds for the selected settings. Try changing the settings\n";
        InputAnyButton();
        system("cls");
        return;
    }
    CursorOn();
    number = InputInteger(DisplayHowManyDisplayResultMenu, 0, Builds->BuildsGetter().size());
    CursorOff();
    
    system("cls");

    std::cout << "--- Builds ---\n\n";

    for (int i = 0; i < number; ++i) {
        std::cout << "--- " << i + 1 << " ---\n";
        std::cout << "Blood Code: " << Builds->BuildsGetter()[i].Blood_code << "\n";
        std::cout << "Weapon: " << Builds->BuildsGetter()[i].Weapon << "\n";
        std::cout << "Blood Veil: " << Builds->BuildsGetter()[i].Blood_veil << "\n";
        std::cout << "Mobility: " << Builds->BuildsGetter()[i].Mobility << "\n";
        std::cout << "Physical damage: " << Builds->BuildsGetter()[i].Physical_damage << "\n";
        std::cout << "Level: " << Builds->BuildsGetter()[i].Level << "\n";
        std::cout << "Weapon Type: " << Builds->BuildsGetter()[i].Weapon_type << "\n";
        std::cout << "Weapon Reinforcement: " << Builds->BuildsGetter()[i].Weapon_reinforcement << "\n";
        std::cout << "Blood Veil Reinforcement: " << Builds->BuildsGetter()[i].Blood_veil_reinforcement << "\n";
        std::cout << "Strength Boosts: " << Builds->BuildsGetter()[i].Str_boosts << "\n";
        std::cout << "Dexterity Boosts: " << Builds->BuildsGetter()[i].Dex_boosts << "\n";
        std::cout << "Mind Boosts: " << Builds->BuildsGetter()[i].Mind_boosts << "\n";
        std::cout << "Willpower Boosts: " << Builds->BuildsGetter()[i].Wil_boosts << "\n\n";
    }
    
    std::cout << "--------------\n";
    std::cout << "Message: " << number << " builds were successfully display!\n\n";
    InputAnyButton();
    system("cls");
}

void SettingMenu(SettingList& Settings, DataStorage& Data)
{
    int choice;
    int page = 1;

    do
    {
        choice = InputButtonMenu(DisplaySettingMenu, Settings, Data, page);

        switch(choice)
        {
        case 0:
            system("cls");
            break;
        case 1:
            system("cls");
            BloodCodeSettingMenu(Settings, Data);
            break;
        case 2:
            system("cls");
            WeaponTypeSettingMenu(Settings);
            break;
        case 3:
            system("cls");
            MobilitySettingMenu(Settings);
            break;
        case 10:
            system("cls");
            break;
        case 11:
            system("cls");
            LevelSettingMenu(Settings);
            break;
        case 12:
            system("cls");
            WeaponReinforcementSettingMenu(Settings);
            break;
        case 13:
            system("cls");
            BloodVeilReinforcementSettingMenu(Settings);
            break;
        case 14:
            system("cls");
            StrBoostsSettingMenu(Settings);
            break;
        case 15:
            system("cls");
            DexBoostsSettingMenu(Settings);
            break;
        case 16:
            system("cls");
            MndBoostsSettingMenu(Settings);
            break;
        case 17:
            system("cls");
            WilBoostsSettingMenu(Settings);
            break;
        default:
            throw "Error: The problem is entering the settings menu";
        }
    } while (choice != 0 && choice != 10);
}

void BloodCodeSettingMenu(SettingList& Settings, DataStorage& Data)
{
    int choice;

    choice = InputButtonMenu(DisplayBloodCodeSettingMenu, Data);

    if (choice < 0) return;
    Settings.BloodCodeSetter(choice);
}

void WeaponTypeSettingMenu(SettingList& Settings)
{
    int choice;

    do
    {
        choice = InputButton(DisplayWeaponTypeSettingMenu);

        if (choice < 1 || choice > 6) {
            system("cls");
            std::cout << "Wrong choice! Try again\n\n";
        } else if (choice) {
            Settings.WeaponTypeSetter(choice - 1);
            system("cls");
        } else system("cls");

    } while (choice < 0 || choice > 6);
}

void MobilitySettingMenu(SettingList& Settings)
{
    int choice;

    do
    {
        choice = InputButton(DisplayMobilitySettingMenu);

        if (choice < 0 || choice > 4) {
            system("cls");
            std::cout << "Wrong choice! Try again\n\n";
        } else if (choice) {
            Settings.MobilitySetter(choice - 1);
            system("cls");
        } else system("cls");

    } while (choice < 0 || choice > 4);
}

void LevelSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayLevelSettingMenu, 1, 300);
    CursorOff();
    
    Settings.LevelSetter(number);

    system("cls");
}

void WeaponReinforcementSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayWeaponReinforcementSettingMenu, 0, 10);
    CursorOff();
    
    Settings.WeaponReinforcementSetter(number);

    system("cls");
}

void BloodVeilReinforcementSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayBloodVeilReinforcementSettingMenu, 0, 10);
    CursorOff();
    
    Settings.BloodVeilReinforcementSetter(number);

    system("cls");
}

void StrBoostsSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayStrBoostsSettingMenu, 0, 10);
    CursorOff();
    
    Settings.StrBoostsSetter(number);

    system("cls");
}

void DexBoostsSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayDexBoostsSettingMenu, 0, 10);
    CursorOff();

    Settings.DexBoostsSetter(number);

    system("cls");
}

void MndBoostsSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayMndBoostsSettingMenu, 0, 10);
    CursorOff();

    Settings.MndBoostsSetter(number);

    system("cls");
}

void WilBoostsSettingMenu(SettingList& Settings)
{
    int number;

    CursorOn();
    number = InputInteger(DisplayWilBoostsSettingMenu, 0, 10);
    CursorOff();

    Settings.WilBoostsSetter(number);

    system("cls");
}
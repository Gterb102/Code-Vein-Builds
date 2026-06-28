#include "Input_Handling.hpp"

void InputAnyButton()
{
    std::cout << "Press any button to continue...";
    getch();
}

int InputButton(void (*Display)())
{
    int n;
    
    Display();
    n = getch();
    std::cout << char(n) << "\n";
    n -= '0';

    return n;
}

int InputInteger(void (*Display)())
{
    int n;
    bool input_error = false;
    std::string s;

    Display();
    std::cin >> n;
    
    if (std::cin.fail()) {
        input_error = true;
        std::cin.clear();
    }
    std::getline(std::cin, s);
    
    while (input_error || !s.empty()) {
        system("cls");
        if (input_error) std::cout << "Error: You need enter only one number! Try again\n\n";
        else if (!s.empty()) std::cout << "Error: You need enter only one number! Try again\n\n";
        s = "";
        input_error = false;
        Display();
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            input_error = true;
        }
        std::getline(std::cin, s);
    }
    return n;
}

int InputInteger(void (*Display)(), int min, int max)
{
    int n;
    bool input_error = false;
    std::string s;

    Display();
    std::cin >> n;
    
    if (std::cin.fail()) {
        input_error = true;
        std::cin.clear();
    }
    std::getline(std::cin, s);
    
    while (input_error || !s.empty() || n > max || n < min) {
        system("cls");
        if (input_error) std::cout << "Error: You need enter only one number! Try again\n\n";
        else if (!s.empty()) std::cout << "Error: You need enter only one number! Try again\n\n";
        else std::cout << "Error: You need enter number from " << min << " to " << max << "! Try again\n\n"; 
        s = "";
        input_error = false;
        Display();
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            input_error = true;
        }
        std::getline(std::cin, s);
    }
    return n;
}

int InputInteger(void (*Display)(int), int min, int max)
{
    int n;
    bool input_error = false;
    std::string s;

    Display(max);
    std::cin >> n;
    
    if (std::cin.fail()) {
        input_error = true;
        std::cin.clear();
    }
    std::getline(std::cin, s);
    
    while (input_error || !s.empty() || n > max || n < min) {
        system("cls");
        if (input_error) std::cout << "Error: You need enter only one number! Try again\n\n";
        else if (!s.empty()) std::cout << "Error: You need enter only one number! Try again\n\n";
        else std::cout << "Error: You need enter number from " << min << " to " << max << "! Try again\n\n"; 
        s = "";
        input_error = false;
        Display(max);
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            input_error = true;
        }
        std::getline(std::cin, s);
    }
    return n;
}

int InputButtonMenu(void (*Display)(SettingList&, DataStorage&, int), SettingList& Settings, DataStorage& Data, int& page)
{
    int c;

    while (1) {
        system("cls");
        Display(Settings, Data, page);
        c = getch();
        if (c == 0 || c == 224) {
            c = getch();
            if (c == 75 && page == 2) --page;
            if (c == 77 && page == 1) ++page;
            continue;
        }

        c -= '0';
        c += (page - 1) * 10;
        if ((c >= 0 && c <= 3) || (c >= 10 && c <= 17)) return c;
    }
}

int InputButtonMenu(void (*Display)(DataStorage&, int), DataStorage& Data)
{
    int max_page = (Data.BloodCodeGetter().size() + 1) / 9;
    int page = 1;
    int c;

    if ((Data.BloodCodeGetter().size() + 1) % 9) ++max_page;
    while (1) {
        system("cls");
        Display(Data, page);
        c = getch();
        if (c == 0 || c == 224) {
            c = getch();
            if (c == 75 && page > 1) --page;
            if (c == 77 && page < max_page) ++page;
            continue;
        }

        c -= '0';
        if (!c) return -1;
        if (c >= 1 && c <= 9 && (page - 1) * 9 + c - 1 <= Data.BloodCodeGetter().size()) return (page - 1) * 9 + c - 1;
    }
}

int InputInteger(void (*Display)(SettingList&), SettingList& Settings)
{
    int n;
    bool input_error = false;
    std::string s;

    Display(Settings);
    std::cin >> n;
    
    if (std::cin.fail()) {
        input_error = true;
        std::cin.clear();
    }
    std::getline(std::cin, s);
    
    while (input_error || !s.empty()) {
        system("cls");
        if (input_error) std::cout << "Error: You need enter only one number! Try again\n\n";
        else if (!s.empty()) std::cout << "Error: You need enter only one number! Try again\n\n";
        s = "";
        input_error = false;
        Display(Settings);
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            input_error = true;
        }
        std::getline(std::cin, s);
    }
    return n;
}
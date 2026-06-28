#include "Interface.hpp"
#include "Data_Storage.hpp"
#include "Build_List.hpp"
#include "Setting_List.hpp"

int main(int argc, char* argv[])
{
    std::string path = argv[0];

    try {
        MainMenu(path);
    } catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 0;
    } catch(const char *errormessage) {
        std::cerr << errormessage << "\n";
    }

    return 0;
}
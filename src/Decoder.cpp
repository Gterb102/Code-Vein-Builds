#include "Decoder.hpp"

int MobilityDecoderStringToInt(std::string mob)
{
    if (mob == "Slow") return 1;
    else if (mob == "Normal") return 2;
    else if (mob == "Quick") return 3;
    else throw std::invalid_argument("Error: Invalid mobility value \"" + mob + "\"!");
}

std::string MobilityDecoderIntToString(int mob)
{
    if (mob == 0) return "Any";
    else if (mob == 1) return "Slow";
    else if (mob == 2) return "Normal";
    else if (mob == 3) return "Quick";
    else throw std::invalid_argument("Error: Invalid mobility value!");
}

std::string WeaponTypeDecoderIntToString(int w_type)
{
    if (w_type == 0) return "Any";
    else if (w_type == 1) return "One-handed Swords";
    else if (w_type == 2) return "Two-handed Swords";
    else if (w_type == 3) return "Halberds";
    else if (w_type == 4) return "Hammers";
    else if (w_type == 5) return "Bayonets";
    else throw std::invalid_argument("Error: Invalid mobility value!");
}

int StatScaling(std::string stat)
{
    if (stat == "-") return 0;
    else if (stat == "E") return 5;
    else if (stat == "E+") return 6;
    else if (stat == "D") return 7;
    else if (stat == "D+") return 8;
    else if (stat == "C") return 9;
    else if (stat == "C+") return 10;
    else if (stat == "B") return 11;
    else if (stat == "B+") return 12;
    else if (stat == "A") return 13;
    else if (stat == "A+") return 14;
    else if (stat == "S") return 15;
    else if (stat == "S+") return 16;
    else throw std::invalid_argument("Error: Invalid stat value!");
}
#ifndef DECODER_HPP
#define DECODER_HPP

#include <string>
#include <stdexcept>

int MobilityDecoderStringToInt(std::string);
std::string MobilityDecoderIntToString(int);
std::string WeaponTypeDecoderIntToString(int);
int StatScaling(std::string);

#endif
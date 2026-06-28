#include "Data_Storage.hpp"
#include <iostream>

DataStorage::DataStorage(std::string path)
{
    path.erase(path.length() - 19);
    blood_codes_path = path + "\\data\\Blood_Code_Data.txt";
    weapons_path = path + "\\data\\Weapon_Data.txt";
    blood_veil_path = path + "\\data\\Blood_Veil_Data.txt";
    
    LoadFromFile(blood_codes_path, weapons_path, blood_veil_path);
}

std::vector<BloodCode>& DataStorage::BloodCodeGetter() {return Blood_codes;}
std::vector<Weapon>& DataStorage::OneHandedSwordGetter() {return One_handed_swords;}
std::vector<Weapon>& DataStorage::TwoHandedSwordGetter() {return Two_handed_swords;}
std::vector<Weapon>& DataStorage::HalberdGetter() {return Halberds;}
std::vector<Weapon>& DataStorage::HammerGetter() {return Hammers;}
std::vector<Weapon>& DataStorage::BayonetGetter() {return Bayonets;}
std::vector<BloodVeil>& DataStorage::BloodVeilGetter() {return Blood_veils;}

void DataStorage::LoadFromFile(std::string blood_codes_path, std::string weapons_path, std::string blood_veil_path)
{
    std::ifstream fin_bc(blood_codes_path, std::ios::in);
    if (!fin_bc) throw "Error: Problem with load Blood Code file!\n\n";

    std::string buf;
    BloodCode blood_code;

    std::getline(fin_bc, buf);
    if (buf != "--- Blood Code ---") throw "Error: Blood code file may be corrupted!";
    std::getline(fin_bc, buf);
    std::getline(fin_bc, buf);
    while (buf != "--- End File ---") {
        if (buf == "") throw "Error: Blood code file may be corrupted!";
        buf.erase(0, 6);
        blood_code.name = buf;

        std::getline(fin_bc, buf);
        buf.erase(0, 10);
        blood_code.mob = MobilityDecoderStringToInt(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 8);
        blood_code.wt = std::stod(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 10);
        blood_code.str = StatScaling(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 11);
        blood_code.dex = StatScaling(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 6);
        blood_code.mnd = StatScaling(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 11);
        blood_code.wil = StatScaling(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 10);
        blood_code.vit = StatScaling(buf);

        std::getline(fin_bc, buf);
        buf.erase(0, 11);
        blood_code.fort = StatScaling(buf);

        Blood_codes.push_back(blood_code);

        std::getline(fin_bc, buf);
        std::getline(fin_bc, buf);
    }

    fin_bc.close();

    std::ifstream fin_w(weapons_path, std::ios::in);
    if (!fin_w) throw "Error: Problem with load Weapon file!\n\n";

    Weapon one_handed_sword;
    Weapon two_handed_sword;
    Weapon halberd;
    Weapon hammer;
    Weapon bayonet;

    std::getline(fin_w, buf);
    if (buf != "--- Weapon ---") throw "Error: Weapon file may be corrupted!";
    std::getline(fin_w, buf);
    std::getline(fin_w, buf);
    if (buf != "--- One-handed Swords ---") throw "Error: Weapon file may be corrupted!";
    std::getline(fin_w, buf);
    std::getline(fin_w, buf);
    while (buf != "--- Two-handed Swords ---") {
        if (buf == "") throw "Error: Weapon file may be corrupted!";
        buf.erase(0, 6);
        one_handed_sword.name = buf;

        std::getline(fin_w, buf);
        buf.erase(0, 22);
        one_handed_sword.bpd = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 8);
        one_handed_sword.wt = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        one_handed_sword.ss_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        one_handed_sword.ss_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        one_handed_sword.ss_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        one_handed_sword.ss_wil = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        one_handed_sword.rs_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        one_handed_sword.rs_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        one_handed_sword.rs_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        one_handed_sword.rs_wil = StatScaling(buf);

        One_handed_swords.push_back(one_handed_sword);

        std::getline(fin_w, buf);
        std::getline(fin_w, buf);
    }

    std::getline(fin_w, buf);
    std::getline(fin_w, buf);
    while (buf != "--- Halberds ---") {
        if (buf == "") throw "Error: Weapon file may be corrupted!";
        buf.erase(0, 6);
        two_handed_sword.name = buf;

        std::getline(fin_w, buf);
        buf.erase(0, 22);
        two_handed_sword.bpd = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 8);
        two_handed_sword.wt = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        two_handed_sword.ss_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        two_handed_sword.ss_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        two_handed_sword.ss_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        two_handed_sword.ss_wil = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        two_handed_sword.rs_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        two_handed_sword.rs_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        two_handed_sword.rs_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        two_handed_sword.rs_wil = StatScaling(buf);

        Two_handed_swords.push_back(two_handed_sword);

        std::getline(fin_w, buf);
        std::getline(fin_w, buf);
    }

    std::getline(fin_w, buf);
    std::getline(fin_w, buf);
    while (buf != "--- Hammers ---") {
        if (buf == "") throw "Error: Weapon file may be corrupted!";
        buf.erase(0, 6);
        halberd.name = buf;

        std::getline(fin_w, buf);
        buf.erase(0, 22);
        halberd.bpd = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 8);
        halberd.wt = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        halberd.ss_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        halberd.ss_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        halberd.ss_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        halberd.ss_wil = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        halberd.rs_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        halberd.rs_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        halberd.rs_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        halberd.rs_wil = StatScaling(buf);

        Halberds.push_back(halberd);

        std::getline(fin_w, buf);
        std::getline(fin_w, buf);
    }

    std::getline(fin_w, buf);
    std::getline(fin_w, buf);
    while (buf != "--- Bayonets ---") {
        if (buf == "") throw "Error: Weapon file may be corrupted!";
        buf.erase(0, 6);
        hammer.name = buf;

        std::getline(fin_w, buf);
        buf.erase(0, 22);
        hammer.bpd = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 8);
        hammer.wt = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        hammer.ss_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        hammer.ss_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        hammer.ss_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        hammer.ss_wil = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        hammer.rs_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        hammer.rs_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        hammer.rs_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        hammer.rs_wil = StatScaling(buf);

        Hammers.push_back(hammer);

        std::getline(fin_w, buf);
        std::getline(fin_w, buf);
    }

    std::getline(fin_w, buf);
    std::getline(fin_w, buf);
    while (buf != "--- End File ---") {
        if (buf == "") throw "Error: Weapon file may be corrupted!";
        buf.erase(0, 6);
        bayonet.name = buf;

        std::getline(fin_w, buf);
        buf.erase(0, 22);
        bayonet.bpd = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 8);
        bayonet.wt = std::stod(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        bayonet.ss_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        bayonet.ss_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        bayonet.ss_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        bayonet.ss_wil = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 13);
        bayonet.rs_str = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        bayonet.rs_dex = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 9);
        bayonet.rs_mnd = StatScaling(buf);

        std::getline(fin_w, buf);
        buf.erase(0, 14);
        bayonet.rs_wil = StatScaling(buf);

        Bayonets.push_back(bayonet);

        std::getline(fin_w, buf);
        std::getline(fin_w, buf);
    }

    fin_w.close();

    std::ifstream fin_bv(blood_veil_path, std::ios::in);
    if (!fin_bv) throw "Error: Problem with load Blood Veil file!\n\n";

    BloodVeil blood_veil;

    std::getline(fin_bv, buf);
    if (buf != "--- Blood Veil ---") throw "Error: Blood Veil file may be corrupted!";
    std::getline(fin_bv, buf);
    std::getline(fin_bv, buf);
    while (buf != "--- End File ---") {
        if (buf == "") throw "Error: Blood Veil file may be corrupted!";
        buf.erase(0, 6);
        blood_veil.name = buf;

        std::getline(fin_bv, buf);
        buf.erase(0, 19);
        blood_veil.bdd = std::stod(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 8);
        blood_veil.wt = std::stod(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 13);
        blood_veil.ss_str = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 14);
        blood_veil.ss_dex = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 9);
        blood_veil.ss_mnd = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 14);
        blood_veil.ss_wil = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 13);
        blood_veil.rs_str = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 14);
        blood_veil.rs_dex = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 9);
        blood_veil.rs_mnd = StatScaling(buf);

        std::getline(fin_bv, buf);
        buf.erase(0, 14);
        blood_veil.rs_wil = StatScaling(buf);

        Blood_veils.push_back(blood_veil);

        std::getline(fin_bv, buf);
        std::getline(fin_bv, buf);
    }

    fin_bv.close();

    return;
}
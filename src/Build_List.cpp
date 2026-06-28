#include "Build_List.hpp"

BuildList::BuildList(DataStorage& Data, SettingList& Settings, std::string path)
{
    Build Build;
    path_file = path.erase(path.length() - 19) + "\\Result.txt";

    Build.Level = Settings.LevelGetter();
    Build.Weapon_reinforcement = Settings.WeaponReinforcementGetter();
    Build.Blood_veil_reinforcement = Settings.BloodVeilReinforcementGetter();
    Build.Str_boosts = Settings.StrBoostsGetter();
    Build.Dex_boosts = Settings.DexBoostsGetter();
    Build.Mind_boosts = Settings.MndBoostsGetter();
    Build.Wil_boosts = Settings.WilBoostsGetter();
    for (int i = 0; i < Data.BloodCodeGetter().size(); ++i) {
        if (Settings.BloodCodeGetter() != 0 && Settings.BloodCodeGetter() - 1 != i) continue;

        Build.Blood_code = Data.BloodCodeGetter()[i].name;

        for (int j = 0; j < Data.OneHandedSwordGetter().size(); ++j) {
            if (Settings.WeaponTypeGetter() != 0 && Settings.WeaponTypeGetter() != 1) break;
            if (Data.OneHandedSwordGetter()[j].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
            if (Data.OneHandedSwordGetter()[j].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
            if (Data.OneHandedSwordGetter()[j].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
            if (Data.OneHandedSwordGetter()[j].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;

            Build.Weapon = Data.OneHandedSwordGetter()[j].name;
            Build.Weapon_type = "One-handed Sword";
            
            Build.Physical_damage = PhysicalDamage(Build.Level, Data.OneHandedSwordGetter()[j].bpd, Build.Weapon_reinforcement, 
            Data.BloodCodeGetter()[i].str, Data.BloodCodeGetter()[i].dex,
            Data.OneHandedSwordGetter()[j].ss_str, Data.OneHandedSwordGetter()[j].ss_dex,
            Build.Str_boosts, Build.Dex_boosts);

            for (int k = 0; k < Data.BloodVeilGetter().size(); ++k) {
                if (Data.BloodVeilGetter()[k].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
                Build.Blood_veil = Data.BloodVeilGetter()[k].name;

                Build.Mobility = MobilityDecoderIntToString(Mobility(Data.BloodCodeGetter()[i].mob, 
                Data.BloodCodeGetter()[i].wt, Data.OneHandedSwordGetter()[j].wt, Data.BloodVeilGetter()[k].wt));

                if (Settings.MobilityGetter() != 0 && Settings.MobilityGetter() != MobilityDecoderStringToInt(Build.Mobility)) continue;
                
                Builds.push_back(Build);
            }
        }

        for (int j = 0; j < Data.TwoHandedSwordGetter().size(); ++j) {
            if (Settings.WeaponTypeGetter() != 0 && Settings.WeaponTypeGetter() != 2) break;
            if (Data.TwoHandedSwordGetter()[j].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
            if (Data.TwoHandedSwordGetter()[j].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
            if (Data.TwoHandedSwordGetter()[j].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
            if (Data.TwoHandedSwordGetter()[j].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
            Build.Weapon = Data.TwoHandedSwordGetter()[j].name;
            Build.Weapon_type = "Two-handed Sword";

            Build.Physical_damage = PhysicalDamage(Build.Level, Data.TwoHandedSwordGetter()[j].bpd, Build.Weapon_reinforcement, 
            Data.BloodCodeGetter()[i].str, Data.BloodCodeGetter()[i].dex,
            Data.TwoHandedSwordGetter()[j].ss_str, Data.TwoHandedSwordGetter()[j].ss_dex,
            Build.Str_boosts, Build.Dex_boosts);

            for (int k = 0; k < Data.BloodVeilGetter().size(); ++k) {
                if (Data.BloodVeilGetter()[k].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
                Build.Blood_veil = Data.BloodVeilGetter()[k].name;

                Build.Mobility = MobilityDecoderIntToString(Mobility(Data.BloodCodeGetter()[i].mob, 
                Data.BloodCodeGetter()[i].wt, Data.TwoHandedSwordGetter()[j].wt, Data.BloodVeilGetter()[k].wt));

                if (Settings.MobilityGetter() != 0 && Settings.MobilityGetter() != MobilityDecoderStringToInt(Build.Mobility)) continue;
                
                Builds.push_back(Build);
            }
        }

        for (int j = 0; j < Data.HalberdGetter().size(); ++j) {
            if (Settings.WeaponTypeGetter() != 0 && Settings.WeaponTypeGetter() != 3) break;
            if (Data.HalberdGetter()[j].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
            if (Data.HalberdGetter()[j].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
            if (Data.HalberdGetter()[j].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
            if (Data.HalberdGetter()[j].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
            Build.Weapon = Data.HalberdGetter()[j].name;
            Build.Weapon_type = "Halberd";

            Build.Physical_damage = PhysicalDamage(Build.Level, Data.HalberdGetter()[j].bpd, Build.Weapon_reinforcement, 
            Data.BloodCodeGetter()[i].str, Data.BloodCodeGetter()[i].dex,
            Data.HalberdGetter()[j].ss_str, Data.HalberdGetter()[j].ss_dex,
            Build.Str_boosts, Build.Dex_boosts);

            for (int k = 0; k < Data.BloodVeilGetter().size(); ++k) {
                if (Data.BloodVeilGetter()[k].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
                Build.Blood_veil = Data.BloodVeilGetter()[k].name;

                Build.Mobility = MobilityDecoderIntToString(Mobility(Data.BloodCodeGetter()[i].mob, 
                Data.BloodCodeGetter()[i].wt, Data.HalberdGetter()[j].wt, Data.BloodVeilGetter()[k].wt));

                if (Settings.MobilityGetter() != 0 && Settings.MobilityGetter() != MobilityDecoderStringToInt(Build.Mobility)) continue;
                
                Builds.push_back(Build);
            }
        }

        for (int j = 0; j < Data.HammerGetter().size(); ++j) {
            if (Settings.WeaponTypeGetter() != 0 && Settings.WeaponTypeGetter() != 4) break;
            if (Data.HammerGetter()[j].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
            if (Data.HammerGetter()[j].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
            if (Data.HammerGetter()[j].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
            if (Data.HammerGetter()[j].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
            Build.Weapon = Data.HammerGetter()[j].name;
            Build.Weapon_type = "Hammer";

            Build.Physical_damage = PhysicalDamage(Build.Level, Data.HammerGetter()[j].bpd, Build.Weapon_reinforcement, 
            Data.BloodCodeGetter()[i].str, Data.BloodCodeGetter()[i].dex,
            Data.HammerGetter()[j].ss_str, Data.HammerGetter()[j].ss_dex,
            Build.Str_boosts, Build.Dex_boosts);

            for (int k = 0; k < Data.BloodVeilGetter().size(); ++k) {
                if (Data.BloodVeilGetter()[k].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
                Build.Blood_veil = Data.BloodVeilGetter()[k].name;

                Build.Mobility = MobilityDecoderIntToString(Mobility(Data.BloodCodeGetter()[i].mob, 
                Data.BloodCodeGetter()[i].wt, Data.HammerGetter()[j].wt, Data.BloodVeilGetter()[k].wt));

                if (Settings.MobilityGetter() != 0 && Settings.MobilityGetter() != MobilityDecoderStringToInt(Build.Mobility)) continue;
                
                Builds.push_back(Build);
            }
        }

        for (int j = 0; j < Data.BayonetGetter().size(); ++j) {
            if (Settings.WeaponTypeGetter() != 0 && Settings.WeaponTypeGetter() != 5) break;
            if (Data.BayonetGetter()[j].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
            if (Data.BayonetGetter()[j].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
            if (Data.BayonetGetter()[j].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
            if (Data.BayonetGetter()[j].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
            Build.Weapon = Data.BayonetGetter()[j].name;
            Build.Weapon_type = "Bayonet";

            Build.Physical_damage = PhysicalDamage(Build.Level, Data.BayonetGetter()[j].bpd, Build.Weapon_reinforcement, 
            Data.BloodCodeGetter()[i].str, Data.BloodCodeGetter()[i].dex,
            Data.BayonetGetter()[j].ss_str, Data.BayonetGetter()[j].ss_dex,
            Build.Str_boosts, Build.Dex_boosts);

            for (int k = 0; k < Data.BloodVeilGetter().size(); ++k) {
                if (Data.BloodVeilGetter()[k].rs_str > Data.BloodCodeGetter()[i].str + Build.Str_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_dex > Data.BloodCodeGetter()[i].dex + Build.Dex_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_mnd > Data.BloodCodeGetter()[i].mnd + Build.Mind_boosts) continue;
                if (Data.BloodVeilGetter()[k].rs_wil > Data.BloodCodeGetter()[i].wil + Build.Wil_boosts) continue;
                Build.Blood_veil = Data.BloodVeilGetter()[k].name;

                Build.Mobility = MobilityDecoderIntToString(Mobility(Data.BloodCodeGetter()[i].mob, 
                Data.BloodCodeGetter()[i].wt, Data.BayonetGetter()[j].wt, Data.BloodVeilGetter()[k].wt));

                if (Settings.MobilityGetter() != 0 && Settings.MobilityGetter() != MobilityDecoderStringToInt(Build.Mobility)) continue;
                
                Builds.push_back(Build);
            }
        }
    }
}

std::vector<Build>& BuildList::BuildsGetter() {return Builds;}
std::string& BuildList::PathFileGetter() {return path_file;}

void BuildList::SortBuilds(std::vector<Build>& Builds)
{
    std::vector<Build> Builds_c = Builds;
    MergeSort(Builds, Builds_c, 0, Builds.size());
}

void BuildList::PrintToFile(std::vector<Build>& Builds, std::string path_file)
{
    std::ofstream fout(path_file, std::ios::out);
    if (!fout) throw "Error: Problem with save file Result.txt!\n\n";
    
    fout << "--- Builds ---\n\n";

    for (int i = 0; i < Builds.size(); ++i) {
        fout << "--- " << i + 1 << " ---\n";
        fout << "Blood Code: " << Builds[i].Blood_code << "\n";
        fout << "Weapon: " << Builds[i].Weapon << "\n";
        fout << "Blood Veil: " << Builds[i].Blood_veil << "\n";
        fout << "Mobility: " << Builds[i].Mobility << "\n";
        fout << "Physical damage: " << Builds[i].Physical_damage << "\n";
        fout << "Level: " << Builds[i].Level << "\n";
        fout << "Weapon Type: " << Builds[i].Weapon_type << "\n";
        fout << "Weapon Reinforcement: " << Builds[i].Weapon_reinforcement << "\n";
        fout << "Blood Veil Reinforcement: " << Builds[i].Blood_veil_reinforcement << "\n";
        fout << "Strength Boosts: " << Builds[i].Str_boosts << "\n";
        fout << "Dexterity Boosts: " << Builds[i].Dex_boosts << "\n";
        fout << "Mind Boosts: " << Builds[i].Mind_boosts << "\n";
        fout << "Willpower Boosts: " << Builds[i].Wil_boosts << "\n\n";
    }

    fout.close();
}
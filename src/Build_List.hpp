#ifndef BUILD_LIST_HPP
#define BUILD_LIST_HPP

#include "Data_Storage.hpp"
#include "Physical_Damage.hpp"
#include "Mobility.hpp"
#include "Merge_Sort.hpp"
#include "Build.hpp"
#include "Decoder.hpp"
#include "Setting_List.hpp"
#include <fstream>
#include <string>
#include <vector>

class BuildList
{

private:

    std::vector<Build> Builds;
    std::string path_file;

public:

    BuildList(DataStorage&, SettingList&, std::string);
    std::vector<Build>& BuildsGetter();
    std::string& PathFileGetter();
    void SortBuilds(std::vector<Build>& Builds);
    void PrintToFile(std::vector<Build>& Builds, std::string path_file);

};

#endif
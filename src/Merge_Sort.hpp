#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include "Build.hpp"
#include "Decoder.hpp"
#include <vector>

void Merge(std::vector<Build>&, std::vector<Build>&, int, int, int);
void MergeSort(std::vector<Build>&, std::vector<Build>&, int, int);

#endif
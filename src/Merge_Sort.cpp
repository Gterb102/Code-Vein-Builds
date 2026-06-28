#include "Merge_sort.hpp"

void Merge(std::vector<Build>& vec, std::vector<Build>& vec_c, int left, int mid, int right) {
    int n = mid;
    int i = left, j = n, k = left;
    
    for (; i < n && j < right; ++k) {
        if (vec[i].Physical_damage > vec[j].Physical_damage) {
            vec_c[k] = vec[i];
            ++i;
        } else if (vec[i].Physical_damage < vec[j].Physical_damage) {
            vec_c[k] = vec[j];
            ++j;
        } else if (MobilityDecoderStringToInt(vec[i].Mobility) > MobilityDecoderStringToInt(vec[j].Mobility)) {
            vec_c[k] = vec[i];
            ++i;
        } else {
            vec_c[k] = vec[j];
            ++j;
        }
    }

    while (i < n) {
        vec_c[k] = vec[i];
        ++k;
        ++i;
    }
    while (j < right) {
        vec_c[k] = vec[j];
        ++k;
        ++j;
    }

    for (i = left; i < right; ++i) vec[i] = vec_c[i];
}

void MergeSort(std::vector<Build>& vec, std::vector<Build>& vec_c, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        MergeSort(vec, vec_c, left, mid);
        MergeSort(vec, vec_c, mid, right);
        Merge(vec, vec_c, left, mid, right);
    }
}
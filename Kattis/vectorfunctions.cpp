// https://open.kattis.com/problems/vectorfunctions

#include "vectorfunctions.h"
#include <algorithm>
#include <numeric>

void backwards(std::vector<int>& vec){
    std::reverse(vec.begin(),  vec.end());
}

std::vector<int> everyOther(const std::vector<int>& vec){
    std::vector<int> ans;
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        if (!(i & 1)) {
            ans.emplace_back(vec[i]);
        }
    }
    return ans;
}

int smallest(const std::vector<int>& vec){
    return *std::min_element(vec.begin(),  vec.end());
}

int sum(const std::vector<int>& vec){
    return std::accumulate(vec.begin(),  vec.end(), 0);
}

int veryOdd(const std::vector<int>& suchVector){
    int counter = 0;
    int n = (int)suchVector.size();
    for (int i = 0; i < n; ++i) {
        if ((i & 1) && (suchVector[i] & 1)) {
            ++counter;
        }
    }
    return counter;
}

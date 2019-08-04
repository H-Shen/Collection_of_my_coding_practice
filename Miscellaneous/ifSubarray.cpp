#include <bits/stdc++.h>

using namespace std;

#define DEBUG

/**
 * A method that checks if b is an subarray of a. If a and b are sorted, please use std::includes instead.
 * @return true if b is an subarray of a, otherwise false
 */
template<typename T>
bool contains(vector<T> const &a, vector<T> const &b) {
    if (b.empty()) {
        return true;
    }
    for (auto i = a.cbegin(), y = a.cend(); i != y; ++i) {
        bool match{true};
        auto ii{i};
        for (auto j = b.cbegin(), z = b.cend(); j != z; ++j) {
            if (ii == a.cend() || *j != *ii) {
                match = false;
                break;
            }
            ii++;
        }
        if (match) {
            return true;
        }
    }
    return false;
}

int main() {

#ifdef DEBUG
    vector<int> A = {1, 5, 76, 8, 2, 32, 3};
    assert(contains(A, vector<int>{1, 5, 76}));
    assert(!contains(A, vector<int>{1, 5, 76, 9}));
    assert(contains(A, vector<int>{8}));
    assert(!contains(A, vector<int>{9}));
    assert(contains(A, vector<int>{}));
    assert(contains(vector<int>{}, vector<int>{}));
#endif

    return 0;
}
#include <bits/stdc++.h>

#define DEBUG

/**
 * A method that checks if b is a subarray of a. If a and b are sorted, please use std::includes instead.
 * @return true if b is an subarray of a, otherwise false
 */
template<typename T>
bool includesWithoutSorting(std::vector<T> const &a, std::vector<T> const &b) {
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
    std::vector<int> A{1, 5, 76, 8, 2, 32, 3};
    assert(includesWithoutSorting(A, std::vector<int>{1, 5, 76}));
    assert(!includesWithoutSorting(A, std::vector<int>{1, 5, 76, 9}));
    assert(includesWithoutSorting(A, std::vector<int>{8}));
    assert(!includesWithoutSorting(A, std::vector<int>{9}));
    assert(includesWithoutSorting(A, std::vector<int>{}));
    assert(includesWithoutSorting(std::vector<int>{}, std::vector<int>{}));
#endif

    return 0;
}

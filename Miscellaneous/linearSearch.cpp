/**
 * Implementations of the algorithm of linear search in Cpp.
 * Compile: g++-7 -std=c++14 -Wall -O2 linearSearch.cpp -o linearSearch
 * Execute: ./linearSearch
 *
 * @author Haohu Shen
 * @date 2019/08/17
 */

#include <bits/stdc++.h>

// Precondition
// 1) A is an array with length n ≥ 1 storing values of some type T that is given as input
// 2) key is an input value with type T.

// Postcondition
// 1) If the key is stored in A then the value returned is an integer i such that A[i]=key. -1 will be returned,
//    otherwise.
// 2) A and key are not changed.

namespace LinearSearch {

    template<typename T>
    inline static
    int linearSearch(const std::vector<T> &A, T key) {
        int i{0};
        int n{static_cast<int>(A.size())};
        while ((i < n) && (A[i] != key)) {
            ++i;
        }
        if (i < n) {
            return i;
        }
        return -1;
    }

    template<typename T, typename Comparator>
    inline static
    int linearSearch(const std::vector<T> &A, T key, Comparator &comp) {
        int i{0};
        int n{static_cast<int>(A.size())};
        while ((i < n) && !comp(A[i], key)) {
            ++i;
        }
        if (i < n) {
            return i;
        }
        return -1;
    }
}


int main() {

    // USAGE
    std::vector<int> A = {2, 3, 3, 4, 7, 7, 7, 9};
    int val = 2;
    std::cout << LinearSearch::linearSearch<int>(A, val) << std::endl;

    val = 7;
    std::cout << LinearSearch::linearSearch<int>(A, val) << std::endl;

    val = 123;
    std::cout << LinearSearch::linearSearch<int>(A, val) << std::endl;

    return 0;
}

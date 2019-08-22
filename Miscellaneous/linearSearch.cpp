/**
 * Implementations of the algorithm of linear search in Cpp.
 * Compile: g++-7 -std=c++14 -Wall -O2 linearSearch.cpp -o linearSearch
 * Execute: ./linearSearch
 *
 * @author Haohu Shen
 * @date 2019/08/17
 */

#include <bits/stdc++.h>

#define DEBUG

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

std::vector<int> generateArrayWithoutDuplicate(int n, int lowerbound, int upperbound) {

    // It is impossible that n is lower than 0 and n == 0 is also not allowed.
    if (n <= 0) {
        throw std::out_of_range("");
    }

    // It is impossible that lowerbound is greater than upperbound.
    if (lowerbound > upperbound) {
        throw std::out_of_range("");
    }

    // If the number between the lowerbound and the upperbound(all inclusive) are smaller than n,
    // then it is impossible to generate n unique numbers.
    if (upperbound - lowerbound + 1 < n) {
        throw std::out_of_range("");
    }


    std::random_device dev;
    std::mt19937 random_generator(dev());
    std::uniform_int_distribution<int> dist(lowerbound, upperbound);
    std::unordered_set<int> Save;

    std::vector<int> result(static_cast<unsigned long>(n));
    int temp;
    for (auto &&i : result) {
        while (true) {
            temp = static_cast<int>(dist(random_generator));
            if (Save.find(temp) == Save.end()) {
                i = temp;
                Save.insert(temp);
                break;
            }
        }
    }
    return result;
}

std::vector<int> generateArrayWithDuplicate(int n, int lowerbound, int upperbound) {

    std::vector<int> result = generateArrayWithoutDuplicate(n, lowerbound, upperbound);
    std::random_device dev;
    std::uniform_int_distribution<unsigned int> dist(0, static_cast<unsigned int>(n - 1));
    std::uniform_int_distribution<int> leftOrRight(0, 1);
    std::mt19937 random_generator(dev());

    if (n == 2) {

        if (leftOrRight(random_generator)) {
            result.at(0) = result.at(1);
        } else {
            result.at(1) = result.at(0);
        }

    } else if (n >= 3) {

        int counter = n / 3;
        while (counter--) {
            int index = static_cast<int>(dist(random_generator));
            if (index == 0) {
                result.at(static_cast<unsigned long>(index) + 1) = result.at(static_cast<unsigned long>(index));
            } else if (index == n - 1) {
                result.at(static_cast<unsigned long>(index - 1)) = result.at(static_cast<unsigned long>(index));
            } else {
                if (leftOrRight(random_generator)) {
                    result.at(static_cast<unsigned long>(index - 1)) = result.at(static_cast<unsigned long>(index));
                } else {
                    result.at(static_cast<unsigned long>(index) + 1) = result.at(static_cast<unsigned long>(index));
                }
            }
        }

    }
    return result;
}

int main() {

#ifdef DEBUG
    std::random_device dev;
    std::mt19937 random_generator(dev());
    int n = 1000;
    std::uniform_int_distribution<unsigned int> index(0, static_cast<unsigned int>(n - 1));
    int testTime = 300;

    // TESTS
    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        int val = A[index(random_generator)];
        assert(std::find(A.begin(), A.end(), val) - A.begin() == LinearSearch::linearSearch<int>(A, val));
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        int val = A[index(random_generator)];
        assert(std::find(A.begin(), A.end(), val) - A.begin() == LinearSearch::linearSearch<int>(A, val));
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        int val = *std::max_element(A.begin(), A.end()) + 1;
        assert(LinearSearch::linearSearch<int>(A, val) == -1);
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        int val = *std::max_element(A.begin(), A.end()) + 1;
        assert(LinearSearch::linearSearch<int>(A, val) == -1);
    }

    auto cmp = [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> int {
        if (lhs.first == rhs.first) {
            return 0;
        } else if (lhs.first > rhs.first) {
            return 1;
        }
        return -1;
    };
    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        std::vector<std::pair<int, int> > A_(A.size());
        for (size_t j = 0; j != A.size(); ++j) {
            A_.at(j) = {A.at(j), A.at(j)};
        }
        auto val = *std::max_element(A_.begin(), A_.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> bool {
            return (lhs.first < rhs.first);
        });
        auto result = LinearSearch::linearSearch<std::pair<int, int> >(A_, val, cmp);
        assert(result != -1);
    }

#endif
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

#include <bits/stdc++.h>

/**
 * An implementation of the insertion sort for solving the 'Sorting in Place' problem. The three-way comparator is
 * supported.
 *
 * Compile: g++-7 -std=c++14 -Wall -O2 insertionSort.cpp -o insertionSort
 * Execute: ./insertionSort
 *
 * @author Haohu Shen
 * @date 2019/08/23
 */

#define DEBUG

namespace InsertionSort {

    /**
     * The "Sorting Larger Subarray" Problem
     *
     * Precondition:
     * a) An array A with length n >= 1, storing elements from some ordered type T, is given as input.
     * b) An integer i such that 1 <= i <= n - 1 is given as input.
     * c) A[h] <= A[h + 1] for every integer h such that 0 <= h <= i - 2
     *
     * Postcondition:
     * a) The entries in A have been reordered or unchanged.
     * b) i has not been changed.
     * c) A[h] <= A[h + 1] for every integer h such that 0 <= h <= i - 1
     *
     *
     * @tparam T some ordered type
     * @param A an array whose base type is T
     * @param i an integer represents an index of an element in A
     */
    template<typename T>
    inline static
    void sortSubarray(std::vector<T> &A, const size_t &i) {
        size_t j = i;
        while ((j > 0) && (A.at(j - 1) > A.at(j))) {
            std::swap(A.at(j), A.at(j - 1));
            --j;
        }
    }

    template<typename T, typename Comparator>
    inline static
    void sortSubarray(std::vector<T> &A, const size_t &i, const Comparator &comp) {
        size_t j = i;
        while ((j > 0) && (comp(A.at(j - 1), A.at(j)) > 0)) {
            std::swap(A.at(j), A.at(j - 1));
            --j;
        }
    }

    template<typename T>
    inline static
    void insertionSort(std::vector<T> &A) {
        size_t i = 1;
        while (i < A.size()) {
            sortSubarray(A, i);
            ++i;
        }
    }

    template<typename T, typename Comparator>
    inline static
    void insertionSort(std::vector<T> &A, const Comparator &comp) {
        size_t i = 1;
        while (i < A.size()) {
            sortSubarray(A, i, comp);
            ++i;
        }
    }
}


int main() {

#ifdef DEBUG
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());

    // Make every entry of the array, the time of tests and the length of the array to be random.
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::uniform_int_distribution<int> test_time_dist(500, 1000);
    std::uniform_int_distribution<unsigned long> len_dist(500ul, 1000ul);

    int test_time = test_time_dist(random_generator);
    while (test_time--) {

        std::vector<int> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = dist(random_generator);
        }
        std::vector<int> A_copy(A.begin(), A.end());

        InsertionSort::insertionSort<int>(A);
        std::sort(A_copy.begin(), A_copy.end());
        assert(A == A_copy);
    }

    class Widget {
    private:
        int first;
        int second;
    public:
        Widget() : Widget(0, 0) {};

        Widget(int first, int second) : first(first), second(second) {}

        bool operator!=(const Widget &rhs) const {
            return (first != rhs.first);
        }

        bool operator<(const Widget &rhs) const {
            return (first < rhs.first);
        }

        bool operator==(const Widget &rhs) const {
            return (first == rhs.first);
        }

        bool operator>(const Widget &rhs) const {
            return (first > rhs.first);
        }

        bool operator>=(const Widget &rhs) const {
            return (first >= rhs.first);
        }

        Widget &operator=(Widget other) {
            first = other.first;
            second = other.second;
            return *this;
        }

        explicit operator std::string() const {
            return "(" + std::to_string(first) + ", " + std::to_string(second) + ")";
        }
    };
    test_time = test_time_dist(random_generator);
    while (test_time--) {
        std::vector<Widget> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = Widget(dist(random_generator), dist(random_generator));
        }
        std::vector<Widget> A_copy(A.begin(), A.end());
        InsertionSort::insertionSort<Widget>(A);
        std::sort(A_copy.begin(), A_copy.end());
        assert(A == A_copy);
    }

    test_time = test_time_dist(random_generator);
    while (test_time--) {
        std::vector<std::pair<int, int> > A(len_dist(random_generator));
        for (auto &&i : A) {
            i = {dist(random_generator), dist(random_generator)};
        }
        std::vector<std::pair<int, int> > A_copy(A.begin(), A.end());

        std::sort(A_copy.begin(), A_copy.end(),
                  [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> bool {
                      if (lhs.first == rhs.first) {
                          return (lhs.second < rhs.second);
                      }
                      return (lhs.first < rhs.first);
                  });
        InsertionSort::insertionSort<std::pair<int, int> >(A, [](const std::pair<int, int> &lhs,
                                                                 const std::pair<int, int> &rhs) -> int {
            if (lhs.first == rhs.first) {
                if (lhs.second > rhs.second) {
                    return 1;
                } else if (lhs.second < rhs.second) {
                    return -1;
                }
                return 0;
            } else if (lhs.first > rhs.first) {
                return 1;
            }
            return -1;
        });
        assert(A_copy == A);
    }

#endif

    return 0;
}

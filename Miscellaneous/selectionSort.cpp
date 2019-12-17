#include <bits/stdc++.h>

/**
 * An implementation of the selection sort for solving the 'Sorting in Place' problem. The three-way comparator is
 * supported.
 *
 * Compile: g++-7 -std=c++14 -Wall -O2 selectionSort.cpp -o selectionSort
 * Execute: ./selectionSort
 *
 * @author Haohu Shen
 * @date 2019/08/22
 */

#define DEBUG

namespace SelectionSort {

    /**
     * Precondition:
     * a) An array A with length n >= 2, storing elements from some ordered type T, is given as input.
     * b) An integer i such that 0 <= i <= n - 2 is given as input.
     *
     * Postcondition:
     * a) The array A and the integer i are not changed.
     * b) An integer "smallest" that satisfies the following properties is returned as output.
     *    1) i <= smallest <= n - 1
     *    2) A[smallest] <= A[h] for every integer h such that i <= h <= n - 1.
     *
     * @tparam T some ordered type
     * @param A an array whose base type is T
     * @param i an integer represents an index of an element in A
     * @return smallest an integer represents an index of an element in A
     */
    template<typename T>
    inline static
    size_t minIndex(const std::vector<T> &A, const size_t &i) {
        size_t j = i + 1;
        size_t smallest = i;
        while (j < A.size()) {
            if (A.at(j) < A.at(smallest)) {
                smallest = j;
            }
            ++j;
        }
        return smallest;
    }

    template<typename T, typename Comparator>
    inline static
    size_t minIndex(const std::vector<T> &A, const size_t &i, const Comparator &comp) {
        size_t j = i + 1;
        size_t smallest = i;
        while (j < A.size()) {
            if (comp(A.at(j), A.at(smallest)) < 0) {
                smallest = j;
            }
            ++j;
        }
        return smallest;
    }

    template<typename T>
    inline static
    void selectionSort(std::vector<T> &A) {

        // Case 1: A.size() <= 1
        if (A.size() <= 1) {
            return;
        }

        // Case 2: A.size() >= 2
        size_t i = 0;
        size_t smallest;
        while (i <= A.size() - 2) {
            smallest = minIndex(A, i);
            std::swap(A.at(smallest), A.at(i));
            ++i;
        }
    }

    template<typename T, typename Comparator>
    inline static
    void selectionSort(std::vector<T> &A, const Comparator &comp) {

        // Case 1: A.size() <= 1
        if (A.size() <= 1) {
            return;
        }

        // Case 2: A.size() >= 2
        size_t i = 0;
        size_t smallest;
        while (i <= A.size() - 2) {
            smallest = minIndex(A, i, comp);
            std::swap(A.at(smallest), A.at(i));
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
    std::uniform_int_distribution<int> test_time_dist(50, 500);
    std::uniform_int_distribution<unsigned long> len_dist(500ul, 1000ul);

    int test_time = test_time_dist(random_generator);
    while (test_time--) {

        std::vector<int> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = dist(random_generator);
        }
        std::vector<int> A_copy(A.begin(), A.end());

        SelectionSort::selectionSort<int>(A);
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
        SelectionSort::selectionSort<Widget>(A);
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
        SelectionSort::selectionSort<std::pair<int, int> >(A, [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> int {
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

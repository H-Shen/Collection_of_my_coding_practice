#include <bits/stdc++.h>

#define DEBUG

namespace MergeSort {

    // Merge two sorted arrays.
    template<typename T>
    std::vector<T> mergeTwoSortedArrays(const std::vector<T> &C1, const std::vector<T> &C2) {

        int n1 = static_cast<int>(C1.size());
        int n2 = static_cast<int>(C2.size());
        std::vector<T> D(C1.size() + C2.size());
        int i1 = 0;
        int i2 = 0;
        int j = 0;

        while ((i1 < n1) && (i2 < n2)) {
            if (C1.at(i1) <= C2.at(i2)) {
                D.at(j) = C1.at(i1);
                ++i1;
            } else {
                D.at(j) = C2.at(i2);
                ++i2;
            }
            ++j;
        }
        while (i1 < n1) {
            D.at(j) = C1.at(i1);
            ++i1;
            ++j;
        }
        while (i2 < n2) {
            D.at(j) = C2.at(i2);
            ++i2;
            ++j;
        }
        return D;
    }

    // Merge two sorted arrays. The three-way comparator is supported.
    template<typename T, typename Comparator>
    std::vector<T> mergeTwoSortedArrays(const std::vector<T> &C1, const std::vector<T> &C2, const Comparator &comp) {

        int n1 = static_cast<int>(C1.size());
        int n2 = static_cast<int>(C2.size());
        std::vector<T> D(C1.size() + C2.size());
        int i1 = 0;
        int i2 = 0;
        int j = 0;

        while ((i1 < n1) && (i2 < n2)) {
            if (comp(C1.at(i1), C2.at(i2)) <= 0) {
                D.at(j) = C1.at(i1);
                ++i1;
            } else {
                D.at(j) = C2.at(i2);
                ++i2;
            }
            ++j;
        }
        while (i1 < n1) {
            D.at(j) = C1.at(i1);
            ++i1;
            ++j;
        }
        while (i2 < n2) {
            D.at(j) = C2.at(i2);
            ++i2;
            ++j;
        }
        return D;
    }

    // MergeSort. The three-way comparator is supported.
    template<typename T, typename Comparator>
    std::vector<T> mergeSort(const std::vector<T> &A, const Comparator &comp) {

        // Case 1:
        if (A.size() <= 1) {
            return A;
        }

        // Case 2:
        int n = static_cast<int>(A.size());
        int n1, n2;

        if (n % 2 == 0) {
            n1 = n / 2;
            n2 = n / 2;
        } else {
            n1 = n / 2 + 1;
            n2 = n / 2;
        }

        std::vector<T> B2(static_cast<unsigned long>(n2));
        std::vector<T> B1(static_cast<unsigned long>(n1));
        int i = 0;

        while (i < n1) {
            B1.at(i) = A.at(i);
            ++i;
        }
        while (i < n) {
            B2.at(i - n1) = A.at(i);
            ++i;
        }
        // Recursively Sort and Merge
        auto C1 = mergeSort(B1, comp);
        auto C2 = mergeSort(B2, comp);
        return mergeTwoSortedArrays(C1, C2, comp);
    }

    // MergeSort
    template<typename T>
    std::vector<T> mergeSort(const std::vector<T> &A) {

        // Case 1:
        if (A.size() <= 1) {
            return A;
        }

        // Case 2:
        int n = static_cast<int>(A.size());
        int n1, n2;

        if (n % 2 == 0) {
            n1 = n / 2;
            n2 = n / 2;
        } else {
            n1 = n / 2 + 1;
            n2 = n / 2;
        }

        std::vector<T> B2(static_cast<unsigned long>(n2));
        std::vector<T> B1(static_cast<unsigned long>(n1));
        int i = 0;

        while (i < n1) {
            B1.at(i) = A.at(i);
            ++i;
        }
        while (i < n) {
            B2.at(i - n1) = A.at(i);
            ++i;
        }
        // Recursively Sort and Merge
        auto C1 = mergeSort(B1);
        auto C2 = mergeSort(B2);
        return mergeTwoSortedArrays(C1, C2);
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
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::min());
    std::uniform_int_distribution<int> test_time_dist(50, 500);
    std::uniform_int_distribution<unsigned long> len_dist(500ul, 1000ul);

    int test_time = test_time_dist(random_generator);
    while (test_time--) {

        std::vector<int> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = dist(random_generator);
        }
        std::vector<int> A_copy(A.begin(), A.end());

        MergeSort::mergeSort<int>(A);
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

        bool operator<=(const Widget &rhs) const {
            return (first <= rhs.first);
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
        MergeSort::mergeSort<Widget>(A);
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
        MergeSort::mergeSort<std::pair<int, int> >(A, [](const std::pair<int, int> &lhs,
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

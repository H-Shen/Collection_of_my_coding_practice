#include <bits/stdc++.h>

/**
 * The heapSort using minHeap for solving the 'Sorting in Place' problem. The three-way comparator is
 * supported.
 * <p>
 * Sorting an array in non-decreasing order when array A with length >= 1,
 * storing elements from some ordered type T using heapsort.
 * </p>
 *
 * Compile: g++-7 -std=c++14 -Wall -O2 heapSort.cpp -o heapSort
 * Execute: ./heapSort
 *
 * @author Haohu Shen
 * @date 2019/08/17
 */

#define DEBUG

namespace HeapSort {

    auto isRoot = [](const int &x) { return (x == 0); };
    auto parent = [](const int &x) {
        if (x == 0) {
            throw std::out_of_range("");
        }
        return (x - 1) / 2;
    };
    auto hasLeft = [](const int &x, const int &heapSize) { return (2 * x + 1 < heapSize); };
    auto left = [](const int &x, const int &heapSize) {
        if (hasLeft(x, heapSize)) {
            return 2 * x + 1;
        }
        throw std::out_of_range("");
    };
    auto hasRight = [](const int &x, const int &heapSize) { return (2 * x + 2 < heapSize); };
    auto right = [](const int &x, const int &heapSize) {
        if (hasRight(x, heapSize)) {
            return 2 * x + 2;
        }
        throw std::out_of_range("");
    };

    template<typename T, typename Comparator>
    inline static
    void bubbleUp(int x, std::vector<T> &A, const Comparator &comp) {
        while (!isRoot(x) && comp(A.at(x), A.at(parent(x))) > 0) {
            std::swap(A.at(x), A.at(parent(x)));
            x = parent(x);
        }
    }

    template<typename T>
    inline static
    void bubbleUp(int x, std::vector<T> &A) {
        while (!isRoot(x) && A.at(x) > A.at(parent(x))) {
            std::swap(A.at(x), A.at(parent(x)));
            x = parent(x);
        }
    }

    template<typename T, typename Comparator>
    inline static
    void bubbleDown(int x, int heapSize, std::vector<T> &A, const Comparator &comp) {
        while (hasLeft(x, heapSize)) {
            if (hasRight(x, heapSize)) {
                if (comp(A.at(left(x, heapSize)), A.at(right(x, heapSize))) >= 0) {
                    if (comp(A.at(left(x, heapSize)), A.at(x)) > 0) {
                        std::swap(A.at(left(x, heapSize)), A.at(x));
                        x = left(x, heapSize);
                    } else {
                        break;
                    }
                } else if (comp(A.at(right(x, heapSize)), A.at(x)) > 0) {
                    std::swap(A.at(right(x, heapSize)), A.at(x));
                    x = right(x, heapSize);
                } else {
                    break;
                }
            } else if (comp(A.at(left(x, heapSize)), A.at(x)) > 0) {
                std::swap(A.at(left(x, heapSize)), A.at(x));
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    }

    template<typename T>
    inline static
    void bubbleDown(int x, int heapSize, std::vector<T> &A) {
        while (hasLeft(x, heapSize)) {
            if (hasRight(x, heapSize)) {
                if (A.at(left(x, heapSize)) >= A.at(right(x, heapSize))) {
                    if (A.at(left(x, heapSize)) > A.at(x)) {
                        std::swap(A.at(left(x, heapSize)), A.at(x));
                        x = left(x, heapSize);
                    } else {
                        break;
                    }
                } else if (A.at(right(x, heapSize)) > A.at(x)) {
                    std::swap(A.at(right(x, heapSize)), A.at(x));
                    x = right(x, heapSize);
                } else {
                    break;
                }
            } else if (A.at(left(x, heapSize)) > A.at(x)) {
                std::swap(A.at(left(x, heapSize)), A.at(x));
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    }

    template<typename T, typename Comparator>
    inline static
    void heapSort(std::vector<T> &A, const Comparator &comp) {
        try {

            int heapSize = 1;
            int i = 1;
            int len = static_cast<int>(A.size());

            while (i < len) {
                if (heapSize < len) {
                    int x = heapSize;
                    A.at(x) = A.at(i);
                    ++heapSize;
                    bubbleUp(x, A, comp);
                } else {
                    throw std::out_of_range("");
                }
                ++i;
            }
            i = len - 1;
            while (i > 0) {
                T largest;
                if (heapSize == 0) {
                    throw std::out_of_range("");
                } else {
                    auto temp = A.at(heapSize - 1);
                    --heapSize;
                    if (heapSize == 0) {
                        largest = temp;
                    } else {
                        largest = A.at(0);
                        A.at(0) = temp;
                        bubbleDown(0, heapSize, A, comp);
                    }
                }
                A.at(i) = largest;
                --i;
            }
        } catch (...) {}
    }

    template<typename T>
    inline static
    void heapSort(std::vector<T> &A) {
        try {
            int heapSize = 1;
            int i = 1;
            int len = static_cast<int>(A.size());

            while (i < len) {
                if (heapSize < len) {
                    int x = heapSize;
                    A.at(x) = A.at(i);
                    ++heapSize;
                    bubbleUp(x, A);
                } else {
                    throw std::out_of_range("");
                }
                ++i;
            }
            i = len - 1;
            while (i > 0) {
                T largest;
                if (heapSize == 0) {
                    throw std::out_of_range("");
                } else {
                    T temp = A.at(heapSize - 1);
                    --heapSize;
                    if (heapSize == 0) {
                        largest = temp;
                    } else {
                        largest = A.at(0);
                        A.at(0) = temp;
                        bubbleDown(0, heapSize, A);
                    }
                }
                A.at(i) = largest;
                --i;
            }
        } catch (...) {}
    }
}


int main() {

#ifdef DEBUG
    std::ios_base::sync_with_stdio(false);

    // Initialize a random number generator.
    std::random_device dev;
    std::mt19937 random_generator(dev());

    // Make every entry of the array, the time of tests and the length of the array to be random.
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    std::uniform_int_distribution<int> test_time_dist(50, 1000);
    std::uniform_int_distribution<unsigned long> len_dist(500ul, 1000ul);

    int test_time = test_time_dist(random_generator);
    while (test_time--) {

        std::vector<int> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = dist(random_generator);
        }
        std::vector<int> A_copy(A.begin(), A.end());

        HeapSort::heapSort<int>(A);
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
        HeapSort::heapSort<Widget>(A);
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

        std::sort(A_copy.begin(), A_copy.end(), [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> bool {
            if (lhs.first == rhs.first) {
                return (lhs.second < rhs.second);
            }
            return (lhs.first < rhs.first);
        });
        HeapSort::heapSort<std::pair<int, int> >(A, [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> int {
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

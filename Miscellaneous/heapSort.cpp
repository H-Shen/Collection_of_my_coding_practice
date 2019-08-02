#include <bits/stdc++.h>

/**
 * The heapSort using minHeap for solving the 'Sorting in Place' problem.
 *
 * <p>
 * Sorting an array in non-decreasing order when array A with length >= 1,
 * storing elements from some ordered type T using heapsort.
 * </p>
 *
 * Compile: g++-7 -std=c++14 -Wall -O2 heapSort.cpp -o heapSort
 * Execute: ./heapSort
 *
 * @author Haohu Shen
 * @date 2019/07/03
 */

using namespace std;

namespace HeapSortWithComparator {

    auto isRoot = [](const int &x) -> bool { return (x == 0); };
    auto parent = [](const int &x) -> int {
        if (x == 0) {
            throw out_of_range("");
        }
        return (x - 1) / 2;
    };

    auto bubbleUp = [](int x, auto &A) -> void {
        while (!isRoot(x) && A.at(x) > A.at(parent(x))) {
            swap(A.at(x), A.at(parent(x)));
            x = parent(x);
        }
    };
    auto hasLeft = [](const int &x, const int &heapSize) -> bool { return (2 * x + 1 < heapSize); };
    auto left = [](const int &x, const int &heapSize) -> int {
        if (hasLeft(x, heapSize)) {
            return 2 * x + 1;
        }
        throw out_of_range("");
    };
    auto hasRight = [](const int &x, const int &heapSize) { return (2 * x + 2 < heapSize); };
    auto right = [](const int &x, const int &heapSize) -> int {
        if (hasRight(x, heapSize)) {
            return 2 * x + 2;
        }
        throw out_of_range("");
    };
    auto bubbleDown = [](int x, int heapSize, auto &A) -> void {
        while (hasLeft(x, heapSize)) {
            if (hasRight(x, heapSize)) {
                if (A.at(left(x, heapSize)) >= A.at(right(x, heapSize))) {
                    if (A.at(left(x, heapSize)) > A.at(x)) {
                        swap(A.at(left(x, heapSize)), A.at(x));
                        x = left(x, heapSize);
                    } else {
                        break;
                    }
                } else if (A.at(right(x, heapSize)) > A.at(x)) {
                    swap(A.at(right(x, heapSize)), A.at(x));
                    x = right(x, heapSize);
                } else {
                    break;
                }
            } else if (A.at(left(x, heapSize)) > A.at(x)) {
                swap(A.at(left(x, heapSize)), A.at(x));
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    };

    template<typename T>
    void heapSort(vector<T> &A) {
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
                    throw out_of_range("");
                }
                ++i;
            }
            i = len - 1;
            while (i > 0) {
                T largest;
                if (heapSize == 0) {
                    throw out_of_range("");
                } else {
                    auto temp = A.at(heapSize - 1);
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
        } catch (...) {
            return;
        }
    }
}

namespace HeapSort {

    inline static
    bool isRoot(const int &x) {
        return (x == 0);
    }

    inline static
    int parent(const int &x) {
        if (x == 0) {
            throw out_of_range("");
        }
        return (x - 1) / 2;
    }

    template<typename T>
    void bubbleUp(int x, vector<T> &A) {
        while (!isRoot(x) && A.at(x) > A.at(parent(x))) {
            swap(A.at(x), A.at(parent(x)));
            x = parent(x);
        }
    }

    inline static
    bool hasLeft(const int &x, const int &heapSize) {
        return (2 * x + 1 < heapSize);
    }

    inline static
    int left(const int &x, const int &heapSize) {
        if (hasLeft(x, heapSize)) {
            return 2 * x + 1;
        }
        throw out_of_range("");
    }

    inline static
    bool hasRight(const int &x, const int &heapSize) {
        return (2 * x + 2 < heapSize);
    }

    inline static
    int right(const int &x, const int &heapSize) {
        if (hasRight(x, heapSize)) {
            return 2 * x + 2;
        }
        throw out_of_range("");
    }

    template<typename T>
    void bubbleDown(int x, int heapSize, vector<T> &A) {
        while (hasLeft(x, heapSize)) {
            if (hasRight(x, heapSize)) {
                if (A.at(left(x, heapSize)) >= A.at(right(x, heapSize))) {
                    if (A.at(left(x, heapSize)) > A.at(x)) {
                        swap(A.at(left(x, heapSize)), A.at(x));
                        x = left(x, heapSize);
                    } else {
                        break;
                    }
                } else if (A.at(right(x, heapSize)) > A.at(x)) {
                    swap(A.at(right(x, heapSize)), A.at(x));
                    x = right(x, heapSize);
                } else {
                    break;
                }
            } else if (A.at(left(x, heapSize)) > A.at(x)) {
                swap(A.at(left(x, heapSize)), A.at(x));
                x = left(x, heapSize);
            } else {
                break;
            }
        }
    }

    template<typename T>
    void heapSort(vector<T> &A) {
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
                    throw out_of_range("");
                }
                ++i;
            }
            i = len - 1;
            while (i > 0) {
                T largest;
                if (heapSize == 0) {
                    throw out_of_range("");
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
        } catch (...) {
            return;
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);

    // Initialize a random number generator.
    random_device dev;
    mt19937 random_generator(dev());

    // Make every entry of the array, the time of tests and the length of the array to be random.
    uniform_int_distribution<std::mt19937::result_type> dist(static_cast<unsigned int>(INT_MIN), INT_MAX);
    uniform_int_distribution<std::mt19937::result_type> test_time_dist(50, 1000);
    uniform_int_distribution<std::mt19937::result_type> len_dist(500, 1000);

    int test_time = test_time_dist(random_generator);
    while (test_time--) {

        vector<int> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = static_cast<int>(dist(random_generator));
        }
        vector<int> A_copy(A.begin(), A.end());

        HeapSort::heapSort(A);
        sort(A_copy.begin(), A_copy.end());
        assert(A == A_copy);
    }
    cout << "Tests passed!" << endl;

    class Widget {
    private:
        int first;
        int second;
    public:
        Widget() : first(0), second(0) {};
        Widget(int first_, int second_) : first(first_), second(second_) {}
        bool operator != (const Widget &rhs) const {
            return (first != rhs.first);
        }
        bool operator < (const Widget &rhs) const {
            return (first < rhs.first);
        }
        bool operator == (const Widget &rhs) const {
            return (first == rhs.first);
        }
        bool operator > (const Widget &rhs) const {
            return (first > rhs.first);
        }
        bool operator >= (const Widget &rhs) const {
            return (first >= rhs.first);
        }
        Widget & operator = (Widget other) {
            first = other.first;
            second = other.second;
            return *this;
        }
        explicit operator string() const {
            return "(" + to_string(first) + ", " + to_string(second) + ")";
        }
    };
    test_time = test_time_dist(random_generator);
    while (test_time--) {
        vector<Widget> A(len_dist(random_generator));
        for (auto &&i : A) {
            i = Widget(static_cast<int>(dist(random_generator)), static_cast<int>(dist(random_generator)));
        }
        vector<Widget> A_copy(A.begin(), A.end());
        HeapSort::heapSort(A);
        sort(A_copy.begin(), A_copy.end());
        assert(A == A_copy);
    }
    cout << "Tests passed!" << endl;

    return 0;
}

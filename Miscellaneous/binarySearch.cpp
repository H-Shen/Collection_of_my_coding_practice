/**
 * An implementation of the algorithm of binary search in Cpp. The three-way comparator is
 * supported.
 *
 * Compile: g++-7 -std=c++14 -Wall -O2 binarySearch.cpp -o binarySearch
 * Execute: ./binarySearch
 *
 * @author Haohu Shen
 * @date 2019/07/12
 */

// 2019/07/28
// The reason why (low + high) / 2 was changed to low + (high - low) / 2 is to avoid the overflow.

#include <bits/stdc++.h>

#define DEBUG

// An implementation of binary search using tail recursion.
// The function will return an index where A[index] = key.
// If the key is not in A, -1 will be returned as output.

namespace BinarySearch {

    template<typename T, typename Comparator>
    inline static
    int bSearch_recursion(const std::vector<T> &A, int low, int high, const T &key, const Comparator &comp) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        int compare = comp(key, A[mid]);
        if (compare < 0) {
            return bSearch_recursion(A, low, mid - 1, key, comp);
        } else if (compare > 0) {
            return bSearch_recursion(A, mid + 1, high, key, comp);
        }
        return mid;
    }

    template<typename T>
    inline static
    int binarySearch_recursion(const std::vector<T> &A, int low, int high, const T &key) {
        if (low > high) {
            return -1;
        }
        int mid = low + (high - low) / 2;
        if (key < A[mid]) {
            return binarySearch_recursion(A, low, mid - 1, key);
        } else if (key > A[mid]) {
            return binarySearch_recursion(A, mid + 1, high, key);
        }
        return mid;
    }


    // An implementation of binary search using 'while' loop.
    // The function will return an index where A[index] = key.
    // If the key is not in A, -1 will be returned as output.

    template<typename T, typename Comparator>
    inline static
    int bSearch(const std::vector<T> &A, const T &key, const Comparator &comp) {
        int low = 0;
        int high = static_cast<int>(A.size()) - 1;
        while (true) {
            if (low > high) {
                return -1;
            }
            int mid = low + (high - low) / 2;
            int compare = comp(key, A[mid]);
            if (compare < 0) {
                high = mid - 1;
            } else if (compare > 0) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
    }

    template<typename T>
    inline static
    int binarySearch(const std::vector<T> &A, const T &key) {
        int low = 0;
        int high = static_cast<int>(A.size()) - 1;
        while (true) {
            if (low > high) {
                return -1;
            }
            int mid = low + (high - low) / 2;
            if (key < A[mid]) {
                high = mid - 1;
            } else if (key > A[mid]) {
                low = mid + 1;
            } else {
                return mid;
            }
        }
    }

    // An implementation of searching for the value with the smallest index by binary search using 'while' loop
    // where there may be multiple keys.
    // It should be used when the user confirmed that the key is in A.

    template<typename T, typename Comparator>
    inline static
    int lowerBound(const std::vector<T> &A, const T &key, const Comparator &comp) {
        int low = 0;
        int high = static_cast<int>(A.size());
        while (true) {
            if (low >= high) {
                return low;
            }
            int mid = low + (high - low) / 2;
            if (comp(key, A[mid]) <= 0) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
    }

    template<typename T>
    inline static
    int lowerBound(const std::vector<T> &A, const T &key) {
        int low = 0;
        int high = static_cast<int>(A.size());
        while (true) {
            if (low >= high) {
                return low;
            }
            int mid = low + (high - low) / 2;
            if (key <= A[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
    }

// An implementation of searching for the value with the (largest index + 1) by binary search using 'while' loop
// where there may be multiple keys.
// It should be used when the user confirmed that the key is in A.

    template<typename T, typename Comparator>
    inline static
    int upperBound(const std::vector<T> &A, const T &key, const Comparator &comp) {
        int low = 0;
        int high = static_cast<int>(A.size());
        while (true) {
            if (low >= high) {
                return low;
            }
            int mid = low + (high - low) / 2;
            if (comp(key, A[mid]) >= 0) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
    }

    template<typename T>
    inline static
    int upperBound(const std::vector<T> &A, const T &key) {
        int low = 0;
        int high = static_cast<int>(A.size());
        while (true) {
            if (low >= high) {
                return low;
            }
            int mid = low + (high - low) / 2;
            if (key >= A[mid]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
    }
}

inline static
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

inline static
std::vector<int> generateArrayWithDuplicate(int n, int lowerbound, int upperbound) {

    std::vector<int> result = generateArrayWithoutDuplicate(n, lowerbound, upperbound);
    std::random_device dev;
    std::uniform_int_distribution<int> dist(0, n - 1);
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

class Widget {
private:
    int first;
    char second;
public:
    Widget(int first, char second) : first(first), second(second) {}

    auto getFirst() const {
        return first;
    }

    bool operator!=(const Widget &rhs) const {
        return (second != rhs.second);
    }

    explicit operator std::string() const {
        return "(" + std::to_string(first) + ",  )";
    }
};

int main() {

#ifdef DEBUG

    // TESTS
    std::random_device dev;
    std::mt19937 random_generator(dev());
    int n = 1000;
    std::uniform_int_distribution<unsigned int> index(0, static_cast<unsigned int>(n - 1));
    int testTime = 300;

    // binarySearch_recursion
    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        assert(BinarySearch::binarySearch_recursion<int>(A, 0, static_cast<int>(A.size()), A[index(random_generator)]) != -1);
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        assert(BinarySearch::binarySearch_recursion<int>(A, 0, static_cast<int>(A.size()), A[index(random_generator)]) != -1);
    }

    // BinarySearch
    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        assert(BinarySearch::binarySearch<int>(A, A[index(random_generator)]) != -1);
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        assert(BinarySearch::binarySearch<int>(A, A[index(random_generator)]) != -1);
    }

    // lowerBound
    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        int val = A[index(random_generator)];
        int index0 = BinarySearch::lowerBound<int>(A, val);
        int index1 = static_cast<int>(std::lower_bound(A.begin(), A.end(), val) - A.begin());
        assert(index0 == index1);
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        int val = A[index(random_generator)];
        int index0 = BinarySearch::lowerBound<int>(A, val);
        int index1 = static_cast<int>(std::lower_bound(A.begin(), A.end(), val) - A.begin());
        assert(index0 == index1);
    }

    // upperBound
    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        int val = A[index(random_generator)];
        int index0 = BinarySearch::upperBound<int>(A, val);
        int index1 = static_cast<int>(std::upper_bound(A.begin(), A.end(), val) - A.begin());
        assert(index0 == index1);
    }

    for (int i = 0; i < testTime; ++i) {
        std::vector<int> A = generateArrayWithoutDuplicate(n, 0, 5 * n);
        std::sort(A.begin(), A.end());
        int val = A[index(random_generator)];
        int index0 = BinarySearch::upperBound<int>(A, val);
        int index1 = static_cast<int>(std::upper_bound(A.begin(), A.end(), val) - A.begin());
        assert(index0 == index1);
    }
#endif

    // USAGE
    std::vector<int> A = {2, 3, 3, 4, 7, 7, 7, 9};
    int val = 2;
    if (BinarySearch::binarySearch<int>(A, val) != -1) {
        std::cout << val << " is found from ";
        std::cout << "index = " << BinarySearch::lowerBound(A, val) << " to ";
        std::cout << "index = " << BinarySearch::upperBound(A, val) - 1 << std::endl;
    }

    val = 7;
    if (BinarySearch::binarySearch<int>(A, val) != -1) {
        std::cout << val << " is found from ";
        std::cout << "index = " << BinarySearch::lowerBound(A, val) << " to ";
        std::cout << "index = " << BinarySearch::upperBound(A, val) - 1 << std::endl;
    }

    auto objVal{Widget(3, 'a')};
    std::vector<Widget> B = {Widget(2, 'q'), Widget(3, 'w'), Widget(3, 'w'), Widget(3, 'p'), Widget(4, 'q')};
    auto threeWayComparator = [](const Widget &lhs, const Widget &rhs) {
        // Only compare if the first members of both objects are the same.
        if (lhs.getFirst() == rhs.getFirst()) {
            return 0;
        } else if (lhs.getFirst() > rhs.getFirst()) {
            return 1;
        }
        return -1;
    };
    if (BinarySearch::bSearch<Widget>(B, objVal, threeWayComparator)) {
        std::cout << std::string(objVal) << " is found from ";
        std::cout << "index = " << BinarySearch::lowerBound<Widget>(B, objVal, threeWayComparator) << " to ";
        std::cout << "index = " << BinarySearch::upperBound<Widget>(B, objVal, threeWayComparator) - 1 << std::endl;
    }
    if (BinarySearch::bSearch_recursion<Widget>(B, 0, static_cast<int>(B.size()), objVal, threeWayComparator)) {
        std::cout << std::string(objVal) << " is found from ";
        std::cout << "index = " << BinarySearch::lowerBound<Widget>(B, objVal, threeWayComparator) << " to ";
        std::cout << "index = " << BinarySearch::upperBound<Widget>(B, objVal, threeWayComparator) - 1 << std::endl;
    }
    return 0;
}

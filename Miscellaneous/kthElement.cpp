#include <vector>
#include <cassert>

// Reference: http://e-maxx.ru/algo/kth_order_statistics
// In the coding-competition, use nth_element instead
// Average Time Cost: O(n)
// If the order is from maximal to minimal: k = n + 1 - k
template<typename T>
T kth_element(std::vector<T> A, int k) {
    int n = static_cast<int>(A.size());
    assert(k >= 0 && k < n);
    int l = 0;
    int r = n - 1;
    int mid;
    while (true) {
        // the current part size is either 1 or 2
        if (r <= l + 1) {
            if (r == l + 1 && A.at(l) > A.at(r)) {
                std::swap(A.at(l), A.at(r));
            }
            return A.at(k);
        }
        // order A[l], A[l+1], A[r]
        mid = (l + r) / 2;
        std::swap(A.at(mid), A.at(l + 1));
        if (A.at(l) > A.at(r)) {
            std::swap(A.at(l), A.at(r));
        }
        if (A.at(l + 1) > A.at(r)) {
            std::swap(A.at(l + 1), A.at(r));
        }
        if (A.at(l) > A.at(l + 1)) {
            std::swap(A.at(l), A.at(l + 1));
        }
        // perform division
        // barrier is A[l + 1]
        int i = l + 1;
        int j = r;
        auto current = A.at(l + 1);
        while (true) {
            while (A.at(++i) < current);
            while (A.at(--j) > current);
            if (i > j) break;
            std::swap(A.at(i), A.at(j));
        }
        // insert the barrier
        A.at(l + 1) = A.at(j);
        A.at(j) = current;
        // continue to work in that part, which must contain the required element
        if (j >= k) {
            r = j - 1;
        }
        if (j <= k) {
            l = i;
        }
    }
}

int main() {

    // test
    std::vector<int> p = {1, 3, 5, 2, 2};
    assert(kth_element(p, 0) == 1);
    assert(kth_element(p, 2) == 2);
    assert(kth_element(p, 4) == 5);

    return 0;
}

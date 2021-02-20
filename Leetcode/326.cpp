template<int N>
struct Pre {
    array<int, N> A;
    constexpr Pre() : A() {
        A.at(0) = 1;
        for (int i = 1; i < N; ++i) {
            A.at(i) = A.at(i - 1) * 3;
        }
    }
};

constexpr int MAXN = 20;
constexpr Pre<MAXN> pre = Pre<MAXN>();

class Solution {
public:
    bool isPowerOfThree(int n) {
        return binary_search(pre.A.begin(), pre.A.end(), n);
    }
};
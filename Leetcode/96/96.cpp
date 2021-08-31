using ull = unsigned long;
constexpr ull N = 20;

constexpr ull f(ull n, ull m) {
    ull sum = 1;
    m = min(n - m, m);
    for(ull i = 1, j = n;i <= m; i++, j--)
        sum = sum * j / i;
    return sum;
}

template<ull N>
struct CombStruct {
    array<int, N> A;
    constexpr CombStruct() : A() {
        for (ull i = 0; i < N; ++i) {
            ull res = f(i << 1, i);
            A[i] = (int)(res / (i+1));
        }
    }
};

CombStruct<N> combStruct;

class Solution {
public:
    int numTrees(int n) {
        return combStruct.A[n];
    }
};
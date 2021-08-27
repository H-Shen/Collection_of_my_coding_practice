class Solution {
public:
    int numTrees(int n) {

        using ull = unsigned long long;
        auto comb = [](ull n, ull m) -> ull {
            ull sum = 1;
            m = min(n - m, m);
            for(ull i = 1, j = n;i <= m; i++, j--)
                sum = sum * j / i;
            return sum;
        };

        ull res = comb((ull)(2 * n), (ull)n);
        return (int)(res / (n + 1));
    }
};
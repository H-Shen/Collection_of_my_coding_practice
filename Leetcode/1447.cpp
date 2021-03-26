class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        constexpr int MAXN = 101;
        bitset<MAXN> vis[MAXN];
        vector<string> toString(MAXN);
        // pre
        for (int i = 1; i < MAXN; ++i) {
            toString[i] = to_string(i);
        }
        // i/j
        int temp;
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= j; ++i) {
                if (i != j) {
                    temp = gcd(i, j);
                    vis[i / temp][j / temp] = true;
                }
            }
        }
        vector<string> result;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = vis[i]._Find_first(); j < MAXN; j = vis[i]._Find_next(j)) {
                result.emplace_back(toString[i] + '/' + toString[j]);   
            }
        }
        return result;
    }
};
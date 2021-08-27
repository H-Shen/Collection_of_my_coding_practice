class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        constexpr int MAXN = 10;
        int freq[MAXN][MAXN]{};
        int u, v;
        for (const auto &i : dominoes) {
            u = i.front();
            v = i.back();
            if (u > v) ++freq[v][u];
            else ++freq[u][v];
        }
        int result = 0;
        for (int i = 1; i <= 9; ++i) {
            for (int j = i; j <= 9; ++j) {
                result += (freq[i][j]*(freq[i][j] - 1)) >> 1;
            }
        }
        return result;
    }
};
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        constexpr int MAXN = 105;
        bitset<MAXN> connect[MAXN];
        vector<int> degree(n);
        for (const auto &i : roads) {
            connect[i[0]][i[1]] = true;
            connect[i[1]][i[0]] = true;
            ++degree[i[0]];
            ++degree[i[1]];
        }
        int maxNetworkRank = 0;
        int networkRank;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (connect[i][j]) {
                    networkRank = degree[i] + degree[j] - 1;
                } else {
                    networkRank = degree[i] + degree[j];
                }
                maxNetworkRank = max(maxNetworkRank, networkRank);
            }
        }
        return maxNetworkRank;
    }
};
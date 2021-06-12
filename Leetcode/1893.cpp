class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        constexpr int MAXN = 55;
        bitset<MAXN> vis;
        for (const auto &i : ranges) {
            for (int j = i[0]; j <= i[1]; ++j) {
                vis[j] = true;
            }
        }
        for (int i = left; i <= right; ++i) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};
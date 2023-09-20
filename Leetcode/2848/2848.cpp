class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        constexpr int MAXN = 105;
        bitset<MAXN> vis;
        for (auto&i : nums) {
            for (int j = i[0]; j <= i[1]; ++j) {
                vis[j] = true;
            }
        }
        return (int)vis.count();
    }
};
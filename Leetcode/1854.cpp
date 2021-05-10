class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        unordered_map<int,int> unmap;
        for (const auto &i : logs) {
            for (int j = i[0]; j <= i[1]-1; ++j) {
                ++unmap[j];
            }
        }
        int maxValue = -1;
        for (const auto &[k,v]:unmap) {
            maxValue = max(maxValue, v);
        }
        int ans = 3000;
        for (const auto &[k,v]:unmap) {
            if (v == maxValue) {
                ans = min(ans, k);
            }
        }
        return ans;
    }
};
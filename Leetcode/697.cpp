class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        constexpr int MAXN = 50005;
        int stats[MAXN]{};
        for (const auto &i : nums) {
            ++stats[i];
        }
        int maxFreq = 0;
        for (int i = 0; i < MAXN; ++i) {
            maxFreq = max(maxFreq, stats[i]);
        }
        unordered_map<int,vector<int> > unmap;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            unmap[nums[i]].emplace_back(i);
        }
        int minDist = numeric_limits<int>::max();
        int length;
        for (const auto &[k,v] : unmap) {
            length = (int)v.size();
            if (length >= maxFreq) {
                for (int i = 0, j = maxFreq - 1; j < length; ++i, ++j) {
                    minDist = min(minDist, v[j] - v[i] + 1);
                }
            }
        }
        return minDist;
    }
};
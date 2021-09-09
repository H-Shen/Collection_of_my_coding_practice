class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, vector<int>> unmap;
        int n = (int)arr.size();
        vector<int> dp(n, 1);
        int ans = 0;
        int val;
        // O(nlogn)
        for (int i = 0; i < n; ++i) {
            val = arr[i]-difference;
            if (unmap.find(val) != unmap.end() && i > unmap[val].front()) {
                auto iter = --lower_bound(unmap[val].begin(),unmap[val].end(),i);
                dp[i] = dp[*iter]+1;
            }
            unmap[arr[i]].emplace_back(i);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
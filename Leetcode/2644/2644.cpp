class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n = (int)divisors.size();
        vector<int> cnt(n);
        for (int i = 0; i < n; ++i) {
            for (const auto& j : nums) {
                if (j % divisors[i] == 0) {
                    ++cnt[i];
                }
            }
        }
        int maxVal = *max_element(cnt.begin(),cnt.end());
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            if (cnt[i] == maxVal) {
                ans = min(ans, divisors[i]);
            }
        }
        return ans;
    }
};
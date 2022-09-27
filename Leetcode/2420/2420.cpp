class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> dp1(n);
        int cnt = 1;
        dp1[0] = cnt;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] < nums[i]) {
                ++cnt;
            }
            dp1[i] = cnt;
        }
        vector<int> dp2(n);
        cnt = 1;
        dp2[0] = cnt;
        for (int i = 1; i < n; ++i) {
            if (nums[i-1] > nums[i]) {
                ++cnt;
            }
            dp2[i] = cnt;
        }
        vector<int> vec;
        for (int i = k; i < n-k; ++i) {
            if (dp1[i-1] == dp1[i-k] && dp2[i+1] == dp2[i+k]) {
                vec.emplace_back(i);
            }
        }
        return vec;
    }
};
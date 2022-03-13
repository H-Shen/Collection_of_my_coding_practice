class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> pos;
        int n = (int)nums.size();
        vector<int> diff(n+1);
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                pos.emplace_back(i);
            }
        }
        int l, r;
        for (auto& j : pos) {
            // -k <= i-j <= k
            // i >= -k+j
            // i <= k+j
            l = max(0, -k+j);
            r = min(k+j, n-1);
            ++diff[l];
            --diff[r+1];
        }
        for (int i = 1; i <= n; ++i) {
            diff[i] += diff[i-1];
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (diff[i] > 0) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
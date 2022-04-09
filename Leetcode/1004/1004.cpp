class Solution {
public:
    int rangeSum(vector<int>&pre, int l, int r) {
        if (l == 0) {
            return pre[r];
        }
        return pre[r] - pre[l-1];
    }
    bool check(vector<int>&pre, int mid, int k, int n) {
        for (int i = 0; i + mid - 1 < n; ++i) {
            if (mid - rangeSum(pre, i, i + mid - 1) <= k) {
                return true;
            }
        }
        return false;
    }
    int longestOnes(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        int l = 1, r = n;
        int mid;
        int ans = numeric_limits<int>::min();
        while (l <= r) {
            mid = l + ((r-l) >> 1);
            if (check(pre, mid, k, n)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans == numeric_limits<int>::min() ? 0 : ans;
    }
};
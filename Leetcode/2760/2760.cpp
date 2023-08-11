class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans = 0;
        int n = (int)nums.size();
        vector<int> pre(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > threshold) {
                pre[i] = 1;
            }
        }
        for (int i = 1; i < n; ++i) {
            pre[i] += pre[i-1];
        }
        auto check1 = [&](int l, int r) {
            if (l == 0) return pre[r] == 0;
            return pre[r] - pre[l-1] == 0;
        };
        auto check2 = [&](int l, int r) {
            for (int i = l; i < r; ++i) {
                if (nums[i] % 2 == nums[i+1] % 2) return false;
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                for (int j = n-1; j >= i; --j) {
                    if (j-i+1 < ans) {
                        break;
                    }
                    if (check1(i,j) && check2(i,j)) {
                        ans = max(ans, j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};
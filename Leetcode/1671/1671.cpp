constexpr int MAXN = 1e3+5;

class Solution {
public:
    // 遍历中间元素 每个元素作为一个peak 找包含它的左边的LIS 找包含它的右边的LDS 然后计算出需要删除的元素
    int minimumMountainRemovals(vector<int>& nums) {
        int dp1[MAXN]{};    // LIS
        int dp2[MAXN]{};    // LDS
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            dp1[i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            dp2[i] = 1;
        }
        for (int i = n-2; i >= 0; --i) {
            for (int j = i+1; j < n; ++j) {
                if (nums[i] > nums[j]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        int ans = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            // LIS和LDS至少都为2
            if (dp1[i] > 1 && dp2[i] > 1) {
                ans = min(ans, (i+1-dp1[i]) + (n-i-dp2[i]));
            }
        }
        return ans;
    }
};
constexpr int MAXN = 202;
constexpr int MAXSUM = 202*102;
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int memo[MAXN][MAXSUM];
    bool DP(vector<int>&nums, int n, int subsetSum) {
        // 此时一个数都不选就行
        if (subsetSum == 0) {
            return true;
        }
        // 此时怎么选都凑不出负数
        if (subsetSum < 0) {
            return false;
        }
        if (n == 0) {
            return false;
        }
        if (memo[n][subsetSum] != INF) {
            return memo[n][subsetSum] == 1;
        }
        // 只要不选最后一个数凑出subsetSum或者选了最后一个数凑出 subsetSum - nums[n-1] 就行
        bool result = DP(nums, n-1, subsetSum) || DP(nums, n-1, subsetSum - nums[n-1]);
        memo[n][subsetSum] = result ? 1 : 0;
        return memo[n][subsetSum] == 1;
    }
    // 备忘录法
    bool canPartition(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return false;
        int sum = 0;
        for (auto&i : nums) sum += i;
        if (sum & 1) return false;
        memset(memo, 0x3f, sizeof memo);
        return DP(nums, n, sum >> 1);
    }
    
    bool canPartition2(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) return false;
        int sum = 0;
        for (auto&i : nums) sum += i;
        if (sum & 1) return false;
        // dp[i][j] = 在0到i范围内选取 和结果为j
        // 不选nums[i]: dp[i][j] = dp[i-1][j]
        // 选nums[i]: 
        // nums[i] == j => dp[i][j] =true
        // nums[i] < j => dp[i][j] = dp[i-1][j-nums[i]] 
        // nums[i] > j => 不能选 超了
        bitset<MAXSUM> dp[MAXN];
        int halfSum = sum >> 1;
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= halfSum; ++j) {
                dp[i][j] = dp[i-1][j];
                // 只要dp[i][j]为true就可以结束判断了
                if (!dp[i][j]) {
                    if (nums[i] == j) {
                        dp[i][j] = true;
                        continue;
                    }
                    else if (nums[i] < j) {
                        dp[i][j] = dp[i-1][j-nums[i]];
                    }
                }
            }
            // prune
            if (dp[i][halfSum]) {
                return true;
            }
        }
        return dp[n-1][halfSum];
    }
};
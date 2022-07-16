using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr ll MAXN = 1e5+5;

ll powmod[MAXN];
bool init = false;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        if (!init) {
            powmod[0] = 1;
            for (int i = 1; i < MAXN; ++i) {
                powmod[i] = (powmod[i-1] * 2LL) % MOD;
            }
            init = true;
        }
        sort(nums.begin(),nums.end());
        ll counter = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            // nums[i] + nums[j] <= target
            // nums[j] <= target - nums[i]
            // j >= i
            auto iter = --upper_bound(nums.begin(),nums.end(),target-nums[i]);
            if (iter != nums.end()) {
                int j = (int)(iter - nums.begin());
                if (j >= i) {
                    counter = counter % MOD + powmod[j - i];
                }
            }
        }
        return (int)(counter % MOD);
    }
};
using ll = long long;

constexpr ll MOD = 1e9+7;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> pre(n+1);
        pre[1] = nums[0];
        for (int i = 2; i <= n; ++i) {
            pre[i] = pre[i-1] + nums[i-1];
        }
        vector<ll> vec((n*(n+1))>>1);
        for (int i = 0, pos = 0; i < n; ++i) {
            for (int j = i; j < n; ++j, ++pos) {
                vec[pos] = pre[j+1] - pre[i];
            }
        }
        sort(vec.begin(),vec.end());
        ll ans = 0;
        --left;
        --right;
        for (int i = left; i <= right; ++i) {
            ans = (ans + vec[i]) % MOD;
        }
        return (int)ans;
    }
};
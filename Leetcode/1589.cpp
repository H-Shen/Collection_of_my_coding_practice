using ll = long long;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        constexpr ll MOD = 1e9+7;
        int n = (int)nums.size();
        vector<int> diff(n+1);
        int l, r;
        for (const auto &i : requests) {
            l = i[0];
            r = i[1];
            ++diff[l];
            --diff[r+1];
        }
        vector<int> pre(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                pre[i] = diff[i];
            } else {
                pre[i] = pre[i-1] + diff[i];
            }
        }
        // greedy
        sort(pre.begin(), pre.end(), greater<>());
        sort(nums.begin(), nums.end(), greater<>());
        ll result = 0;
        for (int i = 0; i < n; ++i) {
            // prune
            if (pre[i] == 0) break;
            result = (result + (ll)pre[i] * nums[i]) % MOD;
        }
        return (int)(result % MOD);
    }
};
using ll = long long;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        ll sum = 0;
        for (const auto &i : nums) sum += i;
        vector<ll> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + (ll)nums[i];
        }
        int m = (int)queries.size();
        vector<ll> ans(m);
        for (int i = 0; i < m; ++i) {
            if (queries[i] > nums[n-1]) {
                ans[i] = (ll)queries[i] * n - sum;
            }
            else if (queries[i] < nums[0]) {
                ans[i] = sum - (ll)queries[i] * n;
            }
            else {
                auto iter = upper_bound(nums.begin(),nums.end(),queries[i]);
                int length1 = (int)(iter - nums.begin());
                int length2 = n - length1;
                ll left = (ll)queries[i]*length1 - pre[length1-1];
                ll right = sum-pre[length1-1] - (ll)queries[i]*length2;
                ans[i] = left + right;
            }
        }
        return ans;
    }
};
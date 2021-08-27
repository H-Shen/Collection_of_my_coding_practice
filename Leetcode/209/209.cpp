using ll = long long;

class Solution {
public:
    // O(nlogn)
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        vector<ll> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + (ll)nums[i-1];
        }
        int minLength = numeric_limits<int>::max();
        for (int i = 0; i <= n; ++i) {
            auto iter = lower_bound(pre.begin(),pre.end(),(ll)target+pre[i]);
            if (iter != pre.end()) {
                minLength = min(minLength, (int)(iter - pre.begin()) - i);
            }
        }
        return (minLength == numeric_limits<int>::max()) ? 0 : minLength;
    }
};
using ll = long long;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = (int)nums.size();
        vector<ll> pre(n);
        ll sum = 0;
        pre[0] = nums[0];
        sum = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
            sum += nums[i];
        }
        ll minDiff = numeric_limits<ll>::max();
        ll l, r;
        ll temp;
        ll ans = -1;
        for (int i = 0; i < n; ++i) {
            l = pre[i] / (ll)(i+1);
            if (n-i-1 == 0) {
                r = 0;
            } else {
                r = (sum - pre[i]) / (ll)(n-i-1);   
            }
            temp = abs(l-r);
            if (temp < minDiff) {
                minDiff = temp;
                ans = i;
            }
        }
        return ans;
    }
};
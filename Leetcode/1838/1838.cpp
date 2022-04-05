using ll = long long;

class Solution {
public:
    // range-sum
    ll rangeSum(vector<ll>&pre, int l, int r) {
        if (l == 0) return pre[r];
        return pre[r] - pre[l-1];
    }
    // calculate the number of operations
    ll op(vector<int>&nums, vector<ll>&pre, int l, int r) {
        if (l == r) return 0;
        return (ll)nums[r]*(r-l) - rangeSum(pre, l, r-1);
    }
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        vector<ll> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1] + nums[i];
        }
        // sliding window
        int l = 0, r = 0;
        int maxFreq = 0;
        ll operations;
        while (r < n) {
            operations = op(nums, pre, l, r);
            if (operations <= k) {
                maxFreq = max(maxFreq, r-l+1);
                ++r;
            }
            else {
                if (l == r) {
                    ++r;
                    ++l;
                }
                else {
                    ++l;
                }
            }
        }

    
        
        return maxFreq;
    }
};
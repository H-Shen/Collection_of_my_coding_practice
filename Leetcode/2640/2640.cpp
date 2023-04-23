using ll = long long;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = (int)nums.size();
        vector<ll> conver(n);
        conver[0] = nums[0] + nums[0];
        ll maxVal = nums[0];
        for (int i = 1; i < n; ++i) {
            maxVal = max(maxVal, (ll)nums[i]);
            conver[i] = nums[i] + maxVal;
        }
        for (int i = 1; i < n; ++i) {
            conver[i] += conver[i-1];
        }
        return conver;
    }
};
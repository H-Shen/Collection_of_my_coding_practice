class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        using ll = long long;
        int n = (int)nums.size();
        ll result = 0;
        for (int i = 0; i < n-2; ++i) {
            for (int j = i+1; j < n-1; ++j) {
                for (int k = j+1; k < n; ++k) {
                    result = max(result, (ll)(nums[i]-nums[j]) * nums[k]);
                }
            }
        }
        return result;
    }
};
using ll = long long;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = (int)nums.size();
        ll maxVal, minVal;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            maxVal = numeric_limits<int>::min();
            minVal = numeric_limits<int>::max();
            for (int j = i; j < n; ++j) {
                maxVal = max(maxVal, (ll)nums[j]);
                minVal = min(minVal, (ll)nums[j]);
                sum += maxVal - minVal;
            }
        }
        return sum;
    }
};
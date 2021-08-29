class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = (int)nums.size();
        int minVal = numeric_limits<int>::max();
        for (int i = 0; i + k - 1 < n; ++i) {
            minVal = min(nums[i+k-1]-nums[i],minVal);
        }
        return minVal;
    }
};
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = (int)nums.size();
        vector<int> ans = {-1,-1};
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (abs(i-j) >= indexDifference && abs(nums[i]-nums[j]) >= valueDifference) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }
        return ans;
    }
};
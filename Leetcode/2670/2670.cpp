class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> diff(n);
        unordered_map<int,int> left;
        ++left[nums[0]];
        unordered_map<int,int> right;
        for (int i = 1; i < n; ++i) {
            ++right[nums[i]];
        }
        for (int i = 0; i < n; ++i) {
            diff[i] = (int)left.size() - (int)right.size();
            // update
            if (i+1<n) {
                ++left[nums[i+1]];
                --right[nums[i+1]];
                if (right[nums[i+1]] == 0) {
                    right.erase(nums[i+1]);
                }
            }
        }
        return diff;
    }
};
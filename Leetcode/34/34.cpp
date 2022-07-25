class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto iter = lower_bound(nums.begin(),nums.end(),target);
        if (iter == nums.end() || *iter != target) {
            return vector<int>{-1,-1};
        }
        vector<int> result(2);
        result[0] = (int)(iter - nums.begin());
        result[1] = (int)((--upper_bound(nums.begin(),nums.end(),target)) - nums.begin());
        return result;
    }
};
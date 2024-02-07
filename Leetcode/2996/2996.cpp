class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = (int)nums.size();
        int s = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] == nums[i-1] + 1) {
                s += nums[i];
            }
            else {
                break;
            }
        }
        unordered_set<int> unset(nums.begin(),nums.end());
        for (int i = s; ; ++i) {
            if (unset.count(i) == 0) return i;
        }
        return -1;
    }
};
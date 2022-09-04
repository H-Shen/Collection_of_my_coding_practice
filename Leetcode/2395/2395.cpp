class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_set<int> vis;
        int temp;
        for (int i = 0; i < n-1; ++i) {
            temp = nums[i] + nums[i+1];
            if (vis.count(temp) > 0) {
                return true;
            }
            vis.insert(temp);
        }
        return false;
    }
};
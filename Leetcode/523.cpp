class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) return false;        
        int n = (int)nums.size();
        int sum = 0;
        unordered_map<int, vector<int> > unmap;
        unmap[0].emplace_back(-1);
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (k == 0) {
                unmap[sum].emplace_back(i);
                if (unmap[sum].back() > unmap[sum].front() + 1) {
                    return true;
                }
            }
            else {
                unmap[sum % k].emplace_back(i);
                if (unmap[sum % k].back() > unmap[sum % k].front() + 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
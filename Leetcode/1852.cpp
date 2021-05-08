class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int k) {
        // sliding window + hashmap
        unordered_map<int, int> unmap;
        int i;
        for (i = 0; i < k; ++i) {
            ++unmap[nums[i]];
        }
        --i;
        int n = (int)nums.size();
        vector<int> result(n - k + 1);
        for (int j = 0; i < n; ++j, ++i) {
            if (j != 0) {
                ++unmap[nums[i]];
                --unmap[nums[j-1]];
                if (unmap[nums[j-1]] == 0) {
                    unmap.erase(nums[j-1]);
                }
            }
            result[j] = (int)unmap.size();
        }
        return result;
    }
};
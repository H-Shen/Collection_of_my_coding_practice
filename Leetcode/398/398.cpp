class Solution {
public:
    unordered_map<int, vector<int> > unmap;
    default_random_engine generator;
    Solution(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n ; ++i) {
            unmap[nums[i]].emplace_back(i);
        }
    }
    
    int pick(int target) {
        uniform_int_distribution<int> distribution(0,(int)unmap[target].size()-1);
        return unmap[target].at(distribution(generator));
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
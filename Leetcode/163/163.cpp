class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        if (nums.empty()) {
            if (lower < upper) {
                ans.emplace_back(to_string(lower) + "->" + to_string(upper));
            }
            else {
                ans.emplace_back(to_string(lower));
            }
            return ans;
        }
        vector<pair<int,int> > vec;
        int n = (int)nums.size();
        if (nums[0] != lower) {
            vec.emplace_back(lower, nums[0]-1);
        }
        for (int i = 0; i < n-1; ++i) {
            if (nums[i]+1 < nums[i+1]) {
                vec.emplace_back(nums[i]+1, nums[i+1]-1);
            }
        }
        if (nums.back() < upper) {
            vec.emplace_back(nums.back()+1, upper);
        }
        for (auto &[i,j] : vec) {
            if (i == j) {
                ans.emplace_back(to_string(i));
            }
            else {
                ans.emplace_back(to_string(i) + "->" + to_string(j));
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int n = (int)nums.size();
        for (auto&i : nums) {
            sort(i.begin(),i.end());
        }
        vector<int> result = nums[0];
        for (int i = 1; i < n; ++i) {
            vector<int> temp;
            set_intersection(result.begin(), result.end(), nums[i].begin(), nums[i].end(), back_inserter(temp));
            swap(result, temp);
        }
        return result;
    }
};
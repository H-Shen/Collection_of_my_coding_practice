class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        int n = (int)index.size();
        for (int i = 0; i < n; ++i) {
            result.insert(result.begin() + index.at(i), nums.at(i));
        }
        return result;
    }
};
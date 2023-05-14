class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int score = 0;
        int n = (int)nums.size();
        for (auto&i : nums) {
            sort(i.begin(),i.end(),greater<>());
        }
        int temp;
        int m = (int)nums[0].size();
        for (int i = 0; i < m; ++i) {
            temp = -1;
            for (int j = 0; j < n; ++j) {
                temp = max(temp, nums[j][i]);
            }
            score += temp;
        }
        return score;
    }
};
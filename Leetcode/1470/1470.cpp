class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        n <<= 1;
        vector<int> result(nums.size());
        auto iter0 = nums.begin();
        auto iter1 = nums.begin() + n / 2;
        for (int i = 0; i < n; i += 2) {
            result.at(i) = *iter0;
            result.at(i + 1) = *iter1;
            ++iter0;
            ++iter1;
        }
        return result;
    }
};
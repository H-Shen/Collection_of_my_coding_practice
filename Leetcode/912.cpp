class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        constexpr int OFFSET = 50000;
        constexpr int MAXN = OFFSET * 2 + 5;
        int stats[MAXN]{};
        for (const auto &i : nums) ++stats[i + OFFSET];
        auto iter = nums.begin();
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] > 0) {
                for (int j = 0; j < stats[i]; ++j) {
                    *iter = i - OFFSET;
                    ++iter;
                }
            }
        }
        return nums;
    }
};
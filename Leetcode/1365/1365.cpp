class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        constexpr int MAXN = 101;
        int freq[MAXN]{};
        for (const auto &i : nums) {
            ++freq[i];
        }
        partial_sum(freq, freq + MAXN, freq);
        for (auto &i : nums) {
            if (__builtin_expect((i != 0), 1)) {
                i= freq[i - 1];
            }
        }
        return nums;
    }
};
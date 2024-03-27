class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        constexpr int N = 105;
        int freq[N]{};
        for (const auto &i : nums) {
            ++freq[i];
            if (freq[i] > 2) return false;
        }
        return true;
    }
};
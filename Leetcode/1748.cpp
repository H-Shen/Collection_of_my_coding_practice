class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        constexpr int MAXN = 101;
        int freq[MAXN]{};
        for (const auto &i : nums) ++freq[i];
        int sum = 0;
        for (int i = 1; i <= MAXN - 1; ++i) if (freq[i] == 1) sum += i;
        return sum;
    }
};
constexpr int MAXN = 105;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int freq[MAXN]{};
        for (auto&i : nums) {
            if (i > 0) {
                ++freq[i];
            }
        }
        int counter = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] > 0) {
                ++counter;
            }
        }
        return counter;
    }
};
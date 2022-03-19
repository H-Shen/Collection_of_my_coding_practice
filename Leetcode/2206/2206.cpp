constexpr int MAXN = 505;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int stats[MAXN]{};
        for (auto&i : nums) {
            ++stats[i];
        }
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] > 0) {
                if (stats[i] & 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
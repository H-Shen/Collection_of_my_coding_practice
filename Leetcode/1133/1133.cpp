class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        constexpr int MAXN = 1005;
        int stats[MAXN]{};
        for (const auto &i : A) ++stats[i];
        for (int i = MAXN - 1; i >= 0; --i) {
            if (stats[i] == 1) {
                return i;
            }
        }
        return -1;
    }
};
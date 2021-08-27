class Solution {
public:
    int findLucky(vector<int>& arr) {
        constexpr int MAXN = 505;
        int freq[MAXN]{};
        for (const auto &i : arr) ++freq[i];
        for (int i = MAXN - 1; i >= 1; --i) {
            if (freq[i] == i) {
                return i;
            }
        }
        return -1;
    }
};
constexpr int MAXN = 26;

class Solution {
public:
    int minSteps(string s, string t) {
        int stats1[MAXN]{};
        for (auto&i : s) {
            ++stats1[i - 'a'];
        }
        int stats2[MAXN]{};
        for (auto&i : t) {
            ++stats2[i - 'a'];
        }
        int counter = 0;
        for (int i = 0; i < MAXN; ++i) {
            counter += abs(stats1[i] - stats2[i]);
        }
        return counter;
    }
};
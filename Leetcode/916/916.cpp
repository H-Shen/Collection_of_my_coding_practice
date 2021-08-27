
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        constexpr int MAXN = 26;
        int stats[MAXN]{};
        for (const auto &i : B) {
            int stats_[MAXN]{};
            for (const auto &ch : i) {
                ++stats_[ch - 'a'];
            }
            for (int j = 0; j < MAXN; ++j) {
                stats[j] = max(stats[j], stats_[j]);
            }
        }
        vector<string> result;
        bool haveAns;
        for (const auto &i : A) {
            haveAns = true;
            int stats1[MAXN]{};
            for (const auto &ch : i) {
                ++stats1[ch - 'a'];
            }
            for (int j = 0; j < MAXN; ++j) {
                if (stats1[j] < stats[j]) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};
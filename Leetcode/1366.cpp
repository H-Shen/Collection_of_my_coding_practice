class Solution {
public:
    string rankTeams(vector<string> &votes) {
        constexpr int MAXN = 26;
        vector<vector<int> > rank(MAXN, vector<int>(MAXN));
        bitset<MAXN> exist;
        for (const auto &s : votes) {
            for (size_t i = 0; i != s.size(); ++i) {
                ++rank.at(s.at(i) - 'A').at(i);
                exist[s.at(i) - 'A'] = true;
            }
        }
        string result;
        for (int i = 0; i < MAXN; ++i) {
            if (exist[i]) {
                result.push_back(i + 'A');
            }
        }
        sort(result.begin(), result.end(), [&](const char &l, const char &r) {
            int leftIndex = l - 'A';
            int rightIndex = r - 'A';
            for (int i = 0; i < MAXN; ++i) {
                if (rank.at(leftIndex) == rank.at(rightIndex)) {
                    continue;
                }
                return rank.at(leftIndex) > rank.at(rightIndex);
            }
            return l < r;
        });
        return result;
    }
};
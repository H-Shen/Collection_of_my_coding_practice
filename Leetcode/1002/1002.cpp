class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        constexpr int MAXN = 26;
        constexpr int INF = 105;
        bitset<MAXN> bs, bs_;
        for (const char &ch : A.front()) {
            bs[ch - 'a'] = true;
        }
        for (size_t i = 1; i != A.size(); ++i) {
            bs_.reset();
            for (const char &ch : A.at(i)) {
                bs_[ch - 'a'] = true;
            }
            bs &= bs_;
        }
        array<short, MAXN> stats{};
        fill(stats.begin(), stats.end(), INF);
        short freq;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (bs[ch - 'a']) {
                for (const auto &i : A) {
                    if (stats[ch - 'a'] == 1) {
                        break;
                    }
                    freq = 0;
                    for (const char &c : i) {
                        if (c == ch) {
                            ++freq;
                        }
                    }
                    stats[ch - 'a'] = min(stats[ch - 'a'], freq);
                }
            }
        }
        vector<string> result;
        string temp = " ";
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] != INF) {
                for (int j = 0; j < stats[i]; ++j) {
                    temp[0] = i + 'a';
                    result.emplace_back(temp);
                }
            }
        }
        return result;
    }
};
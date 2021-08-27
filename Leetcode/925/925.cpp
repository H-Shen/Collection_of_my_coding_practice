class Solution {
public:
    vector<pair<char, int> > f(const string &s) {
        char ch = 0;
        int freq = 0;
        vector<pair<char, int> > result;
        for (const auto &i : s) {
            if (ch == 0) {
                ch = i;
                freq = 1;
                continue;
            }
            if (i == ch) {
                ++freq;
            }
            else {
                result.emplace_back(ch, freq);
                ch = i;
                freq = 1;
            }
        }
        if (ch != 0) {
            result.emplace_back(ch, freq);
        }
        return result;
    }
    bool isLongPressedName(string name, string typed) {
        auto a = f(name);
        auto b = f(typed);
        if (a.size() == b.size()) {
            int n = (int)a.size();
            for (int i = 0; i < n; ++i) {
                if (a[i].first != b[i].first || a[i].second > b[i].second) {
                    return false;         
                }
            }
            return true;
        }
        return false;
    }
};
constexpr int MAXN = 26;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        if (s.empty()) return s;
        int stats[MAXN]{};
        for (auto& i : s) {
            ++stats[i - 'a'];
        }
        map<char,int,greater<>> m;
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] != 0) m[i + 'a'] = stats[i];
        }
        string result;
        while (true) {
            auto iter = m.begin();
            char ch = iter->first;
            int temp = min(iter->second, repeatLimit);
            for (int i = 0; i < temp; ++i) {
                result.push_back(ch);
                iter->second--;
            }
            if (m.size() == 1) break;
            if (iter->second == 0) {
                m.erase(iter);
                if (m.empty()) break;
            }
            else {
                auto iter2 = iter;
                iter2++;
                if (iter2 == m.end()) {
                    break;
                }
                result.push_back(iter2->first);
                iter2->second--;
                if (iter2->second == 0) {
                    m.erase(iter2);
                }
            }
        }
        return result;
    }
};
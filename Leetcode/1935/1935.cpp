class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        constexpr int N = 26;
        bitset<N> bs;
        for (const auto &ch : brokenLetters) {
            bs[ch - 'a'] = true;
        }
        istringstream iss(text);
        vector<string> v;
        string str;
        do {
            iss >> str;
            v.emplace_back(str);
        } while (iss);
        v.pop_back();
        int counter = 0;
        for (const auto &i : v) {
            bool flag = true;
            for (const auto &j : i) {
                if (bs[j-'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) ++counter;
        }
        return counter;
    }
};
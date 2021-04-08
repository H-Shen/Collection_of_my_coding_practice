class Solution {
public:
    int compress(vector<char>& chars) {
        char c;
        int freq = 0;
        vector<pair<char, int> > v;
        for (const char &ch : chars) {
            if (freq == 0) {
                c = ch;
                freq = 1;
            }
            else if (ch == c) {
                ++freq;
            }
            else {
                v.emplace_back(c, freq);
                c = ch;
                freq = 1;
            }
        }
        if (freq > 0) {
            v.emplace_back(c, freq);
        }
        vector<char>().swap(chars);
        string s;
        for (const auto &[i, j] : v) {
            chars.emplace_back(i);
            if (j > 1) {
                s = to_string(j);
                for (const char &k : s) {
                    chars.emplace_back(k);
                }
            }
        }
        return chars.size();
    }
};
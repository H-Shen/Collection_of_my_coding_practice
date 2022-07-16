class Solution {
public:
    inline
    vector<pair<char,int>> parse(const string& s) {
        vector<pair<char,int>> vec;
        char lastChar;
        int freq = 0;
        for (auto& ch : s) {
            if (freq == 0) {
                freq = 1;
                lastChar = ch;
                continue;
            }
            if (ch == lastChar) {
                ++freq;
            }
            else {
                vec.emplace_back(lastChar, freq);
                lastChar = ch;
                freq = 1;
            }
        }
        if (freq > 0) {
            vec.emplace_back(lastChar, freq);
        }
        return vec;
    }
    int expressiveWords(string s, vector<string>& words) {
        auto p = parse(s);
        int counter = 0;
        for (auto& word : words) {
            auto vec = parse(word);
            if (vec.size() != p.size()) {
                continue;
            }
            bool haveAns = true;
            for (size_t i = 0; i != vec.size(); ++i) {
                if (vec[i].first != p[i].first) {
                    haveAns = false;
                    break;
                }
                if (vec[i].second != p[i].second) {
                    if (vec[i].second <= p[i].second && p[i].second >= 3) {
                        continue;
                    }
                    else {
                        haveAns = false;
                        break;
                    }
                }
            }
            if (haveAns) {
                ++counter;
            }
        }
        return counter;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> s_cnt;
        for (const auto &i : s) {
            ++s_cnt[i];
        }

        unordered_map<char, int> t_cnt;
        for (const auto &i : t) {
            ++t_cnt[i];
        }

        char res = '\0';
        for (const auto it : t_cnt) {
            if (s_cnt.find(it.first) == s_cnt.end() || s_cnt[it.first] < it.second) {
                res = it.first;
                break;
            }
        }

        return res;
    }
};
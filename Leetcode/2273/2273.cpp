constexpr int MAXN = 26;

int freq1[MAXN];
int freq2[MAXN];

class Solution {
public:
    inline
    bool check(string& l, string& r) {
        memset(freq1, 0, sizeof freq1);
        memset(freq2, 0, sizeof freq2);
        for (auto& i : l) {
            ++freq1[i - 'a'];
        }
        for (auto& i : r) {
            ++freq2[i - 'a'];
        }
        for (int i = 0; i < MAXN; ++i) {
            if (freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        for (auto& word : words) {
            if (result.empty()) {
                result.emplace_back(word);
                continue;
            }
            if (!check(word, result.back())) {
                result.emplace_back(word);
            }
        }
        return result;
    }
};
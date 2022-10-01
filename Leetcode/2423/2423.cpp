constexpr int MAXN = 26;

class Solution {
public:
    bool equalFrequency(string word) {
        int freq[MAXN]{};
        for (auto&ch : word) {
            ++freq[ch - 'a'];
        }
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] > 0) {
                --freq[i];
                unordered_set<int> temp;
                bool flag = true;
                for (int j = 0; j < MAXN; ++j) {
                    if (freq[j] > 0) {
                        temp.insert(freq[j]);
                        if (temp.size() > 1) {
                            flag = false;
                            break;
                        }
                    }
                }
                if (flag) {
                    return true;
                }
                ++freq[i];
            }
        }
        return false;
    }
};
constexpr int MAXN = 26;

class Solution {
public:
    // Greedy + Freq count
    vector<int> partitionLabels(string s) {
        int freq[MAXN]{};
        for (auto& ch : s) ++freq[ch - 'a'];
        int currentFreq[MAXN]{};
        bool check;
        int n = (int)s.size();
        int length;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ++currentFreq[s[i] - 'a'];
                --freq[s[i] - 'a'];
                continue;
            }
            check = false;
            for (int j = 0; j < MAXN; ++j) {
                if (currentFreq[j] > 0 && freq[j] > 0) {
                    ++currentFreq[s[i] - 'a'];
                    --freq[s[i] - 'a'];
                    check = true;
                    break;
                }
            }
            if (!check) {
                length = 0;
                for (int j = 0; j < MAXN; ++j) {
                    length += currentFreq[j];
                }
                ans.emplace_back(length);
                memset(currentFreq, 0, sizeof currentFreq);
                ++currentFreq[s[i] - 'a'];
                --freq[s[i] - 'a'];
            }
        }
        length = 0;
        for (int j = 0; j < MAXN; ++j) {
            length += currentFreq[j];
        }
        if (length > 0) {
            ans.emplace_back(length);
        }
        return ans;
    }
};
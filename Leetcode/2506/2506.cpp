constexpr int MAXN = 26;

class Solution {
public:
    inline
    bool similar(const string&l, const string&r) const {
        int freq1[MAXN]{};
        for (auto& ch : l) ++freq1[ch - 'a'];
        int freq2[MAXN]{};
        for (auto& ch : r) ++freq2[ch - 'a'];
        for (int i = 0; i < MAXN; ++i) {
            if ( (freq1[i] == 0 && freq2[i] != 0) || (freq1[i] != 0 && freq2[i] == 0) ) {
                return false;
            }
        }        
        return true;
    }
    int similarPairs(vector<string>& words) {
        int n = (int)words.size();
        int ans = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                if (similar(words[i], words[j])) {
                    ++ans;
                }
            }
        }
        return ans;
    }
};
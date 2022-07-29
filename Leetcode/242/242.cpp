class Solution {
public:
    bool isAnagram(string s, string t) {
        constexpr int MAXN = 26;
        vector<int> freq1(MAXN);
        for (auto& i : s) ++freq1[i - 'a'];
        vector<int> freq2(MAXN);
        for (auto& i : t) ++freq2[i - 'a'];
        return freq1 == freq2;
    }
};
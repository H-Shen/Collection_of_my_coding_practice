class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<pair<char,int> > v;
        int n = (int)s.size();
        char last;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                last = s[i];
                counter = 1;
                continue;
            }
            if (s[i] == last) {
                ++counter;
            }
            else {
                v.emplace_back(last, counter);
                last = s[i];
                counter = 1;
            }
        }
        v.emplace_back(last, counter);
        int ans = 0;
        int length = (int)v.size();
        if (length > 1) {
            for (int i = 0; i < length - 1; ++i) {
                ans += min(v[i].second,v[i+1].second);
            }
        }
        return ans;
    }
};
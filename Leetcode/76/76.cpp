class Solution {
public:
    string minWindow(string s, string t) {
        constexpr int MAXN = 128;
        int m = (int)s.size();
        int stats[MAXN]{};
        for (const char &ch : t) ++stats[ch];
        int frontIndex = 0;
        int stats2[MAXN]{};
        int minLength = numeric_limits<int>::max();
        int lastIndexOfMinLength = -1;
        bool flag;
        for (int i = 0; i < m; ++i) {
            ++stats2[s[i]];
            while (frontIndex <= i && stats2[s[frontIndex]] > stats[s[frontIndex]]) {
                --stats2[s[frontIndex]];
                ++frontIndex;
            }
            flag = true;
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                if (stats2[ch] < stats[ch]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                for (char ch = 'A'; ch <= 'Z'; ++ch) {
                    if (stats2[ch] < stats[ch]) {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag && minLength > i-frontIndex+1) {
                minLength = i-frontIndex+1;
                lastIndexOfMinLength = i;
            }
        }
        return (lastIndexOfMinLength == -1) ? string() : string(s.begin()+lastIndexOfMinLength-(minLength-1), s.begin()+lastIndexOfMinLength+1);
    }
};
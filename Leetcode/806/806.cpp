class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        constexpr int MAXN = 100;
        int lineCounter = 1;
        int lastLineTotalPixel = 0;
        int n = (int)s.size();
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += widths[s[i] - 'a'];
            if (cur > MAXN) {
                ++lineCounter;
                lastLineTotalPixel = widths[s[i] - 'a'];
                cur = widths[s[i] - 'a'];
            }
            else {
                lastLineTotalPixel += widths[s[i] - 'a'];
            }
        }
        return vector<int>{lineCounter, lastLineTotalPixel};
    }
};
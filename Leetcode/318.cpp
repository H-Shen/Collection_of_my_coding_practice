constexpr int MAXN = 26;

class Solution {
public:
    vector<array<int, MAXN> > stats;
    bool shareCommon(int i, int j) {
        for (int idx = 0; idx < MAXN; ++idx) {
            if (stats[i][idx] > 0 && stats[j][idx] > 0) {
                return true;
            }
        }
        return false;
    }
    int maxProduct(vector<string>& words) {
        int n = (int)words.size();
        stats.resize(n);
        for (int i = 0; i < n; ++i) {
            for (const char &ch : words[i]) {
                ++stats[i][ch - 'a'];
            }
        }
        int result = 0;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!shareCommon(i, j)) {
                    result = max(result, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return result;
    }
};
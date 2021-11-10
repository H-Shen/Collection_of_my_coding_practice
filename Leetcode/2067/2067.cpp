constexpr int N = 26;
constexpr int MAXN = 3*1e4+5;
int pre[MAXN][N];
int stats[N];

class Solution {
public:
    bool check(int l, int r, int count) {
        memset(stats, 0, sizeof stats);
        for (int i = 0; i < N; ++i) {
            stats[i] = pre[r][i] - pre[l-1][i];
        }
        for (int i = 0; i < N; ++i) {
            if (stats[i] > 0 && stats[i] != count) return false; 
        }
        return true;
    }
    int equalCountSubstrings(string s, int count) {
        memset(pre, 0, sizeof pre);
        int n = (int)s.size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < N; ++j) {
                pre[i][j] = pre[i-1][j]; 
            }
            ++pre[i][s[i-1]-'a'];
        }
        int counter = 0;
        int length, l, r;
        for (int i = 1; i <= N; ++i) {
            length = i * count;
            for (l = 1;; ++l) {
                r = l+length-1;
                if (r > n) break;
                if (check(l, r, count)) ++counter;
            }
        }
        return counter;
    }
};
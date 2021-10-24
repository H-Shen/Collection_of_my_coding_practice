constexpr int MAXN = 10;
constexpr int INF = 0x3f3f3f3f;
int stats[MAXN];

bool check(int n) {
    string s = to_string(n);
    memset(stats, 0x3f, sizeof stats);
    int temp;
    for (auto &ch : s) {
        temp = ch-'0';
        if (stats[temp] == INF) {
            stats[temp] = 1;
        } else {
            ++stats[temp];
            // prune
            if (stats[temp] > temp) {
                return false;
            }
        }
    }
    for (int i = 0; i < MAXN; ++i) {
        if (stats[i] != INF && stats[i] != i) return false;
    }
    return true;
}
class Solution {
public:
    int nextBeautifulNumber(int n) {
        for (int i = n+1;; ++i) {
            if (check(i)) return i;
        }
        return 0;
    }
};
// https://open.kattis.com/problems/warehouse
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 20;
char s[MAXN];

int main() {

    int t;
    int n;
    int count;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        unordered_map<string, int> stats;
        for (int i = 0; i < n; ++i) {
            scanf("%s %d", s, &count);
            stats[s] += count;
        }
        vector<pair<string, int> > temp(stats.begin(), stats.end());
        sort(temp.begin(), temp.end(), [](const pair<string, int> &lhs, const pair<string, int> &rhs) {
            if (lhs.second == rhs.second) {
                return (lhs.first < rhs.first);
            }
            return (lhs.second > rhs.second);
        });
        printf("%d\n", static_cast<int>(temp.size()));
        for (const auto &[key, value] : temp) {
            printf("%s %d\n", key.c_str(), value);
        }
    }

    return 0;
}

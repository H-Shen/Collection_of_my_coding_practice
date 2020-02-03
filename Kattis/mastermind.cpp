// https://open.kattis.com/problems/mastermind
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 60;
char a_cstr[MAXN];
char b_cstr[MAXN];

int main() {

    int n;
    int r = 0;
    int s = 0;
    scanf("%d %s %s", &n, a_cstr, b_cstr);
    string a(a_cstr);
    string b(b_cstr);
    unordered_set<int> same_position_same_color;
    for (int i = 0; i < n; ++i) {
        if (a.at(i) == b.at(i)) {
            same_position_same_color.insert(i);
            ++r;
        }
    }
    unordered_map<char, int> a_stats;
    unordered_map<char, int> b_stats;
    for (int i = 0; i < n; ++i) {
        if (same_position_same_color.find(i) != same_position_same_color.end()) {
            continue;
        }
        ++a_stats[a.at(i)];
        ++b_stats[b.at(i)];
    }
    for (const auto &[k, v] : a_stats) {
        if (b_stats.find(k) != b_stats.end()) {
            s += min(v, b_stats[k]);
        }
    }
    printf("%d %d\n", r, s);

    return 0;
}

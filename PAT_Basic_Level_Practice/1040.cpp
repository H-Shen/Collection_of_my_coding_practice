#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int maxn = 100005;
const ll mod = 1000000007;
char s[maxn];

int main() {
    scanf("%s", s);
    ll pat_cnt = 0, at_cnt = 0, t_cnt = 0;
    for (int i = static_cast<int>(strlen(s) - 1); i >= 0; --i) {
        if (s[i] == 'T') {
            ++t_cnt;
        } else if (s[i] == 'A') {
            at_cnt = (at_cnt + t_cnt) % mod;
        } else {
            pat_cnt = (pat_cnt + at_cnt) % mod;
        }
    }
    printf("%lld\n", pat_cnt);
    return 0;
}
// https://open.kattis.com/problems/bits
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 105;
char s[MAXN];

int solve(const string &num_str) {
    ll temp = stoll(num_str);
    return __builtin_popcount(temp);
}

int main() {

    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; ++i) {
        int maxCnt = 0;
        scanf("%s", s);
        string num_str;
        for (int j = 0; s[j] != 0; ++j) {
            num_str.push_back(s[j]);
            maxCnt = max(solve(num_str), maxCnt);
        }
        printf("%d\n", maxCnt);
    }

    return 0;
}

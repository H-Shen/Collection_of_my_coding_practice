// https://open.kattis.com/problems/deathknight
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1005;
char s[MAXN];

int main() {

    int cnt = 0;
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        if (!strstr(s, "CD")) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);

    return 0;
}

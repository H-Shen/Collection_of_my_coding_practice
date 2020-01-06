// https://open.kattis.com/problems/permutationdescent
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 1003;

ll PDC[maxn][maxn];

int main() {

    for (int i = 1; i < maxn; ++i) {
        PDC[i][i] = 0;
        PDC[i][0] = 1;
        for (int j = 1; j < i; ++j) {
            PDC[i][j] =
                    ((i - j) * PDC[i - 1][j - 1] + (j + 1) * PDC[i - 1][j]) %
                    1001113;
        }
    }

    ll n, v;
    int t, kase;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld %lld", &kase, &n, &v);
        printf("%d %lld\n", kase, PDC[n][v]);
    }

    return 0;
}

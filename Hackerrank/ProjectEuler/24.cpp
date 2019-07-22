#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

//preComputation
const ll factorial[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800};
const ll INTERVAL = 96;

void reverseCantorExpansion(vector<ll> &s, ll length, ll k) { //1-length, s should be all 0s

    bool *vis = (bool *)malloc(sizeof(bool) * (length + 1));
    memset(vis, 0, sizeof(vis));

    ll i, j, t;
    k--;
    for (i = 0; i < length; i++) {
        t = k / factorial[length - i - 1];
        for (j = 1; j <= length; j++) {
            if (!vis[j]) {
                if (t == 0)
                    break;
                t--;
            }
        }
        s[i] = j;
        vis[j] = true;
        k %= factorial[length - i - 1];
    }
}

int main() {

    int T;
    ll K;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld", &K);
        vector<ll> a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        ll len = static_cast<ll>(a.size());
        reverseCantorExpansion(a, len, K);

        for (ll i = 0; i < len; i++)
            printf("%c", (char)(a[i] + INTERVAL));
        printf("\n");
    }
    return 0;
}

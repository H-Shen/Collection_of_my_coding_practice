// https://open.kattis.com/problems/zebrasocelots
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 5;
char s[MAXN];

inline static
ll quickPower(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

int main() {


    int n;
    scanf("%d", &n);
    string str(n, '0');
    for (int i = n - 1; i >= 0; --i) {
        scanf("%s", s);
        if (s[0] == 'Z') {
            str.at(i) = '1';
        }
    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        if (str.at(i) == '0') {
            result += quickPower(2, static_cast<ll>(i));
        }
    }
    printf("%lld\n", result);

    return 0;
}

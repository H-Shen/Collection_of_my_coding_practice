// https://open.kattis.com/problems/pot
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 10;
char s[MAXN];

inline static
ll my_pow(ll a, ll n) {
    if (n == 0) {
        return 1;
    }
    if (a == 0) {
        return 0;
    }
    ll result = 1;
    for (ll i = 1; i <= n; ++i) {
        result *= a;
    }
    return result;
}

int main() {

    int t;
    ll sum = 0;
    ll a, n;
    string str;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        str = s;
        n = str.back() - '0';
        str.pop_back();
        a = stoll(str);
        sum += my_pow(a, n);
    }
    printf("%lld\n", sum);

    return 0;
}

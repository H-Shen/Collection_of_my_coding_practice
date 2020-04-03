// https://open.kattis.com/problems/emergency
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

__int128 N, K;
__int128 sum = 0;

string printInt128(__int128 a) {
    if (!a) return "0";
    string s;
    while (a) {
        s = char(abs(a % 10) + '0') + s;
        if (-10 < a && a < 0) s = '-' + s;
        a /= 10;
    }
    return s;
}

int main() {

    ll n, k;
    scanf("%lld %lld", &n, &k);
    N = n;
    K = k;
    if (N - 1 <= K) {
        sum = N - 1;
    } else {
        sum = min(N - 1, K + 1 + (N - 1) % K);
    }
    printf("%s\n", printInt128(sum).c_str());

    return 0;
}

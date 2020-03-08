// https://open.kattis.com/problems/threedigits
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr __int128 MOD = 1000000000000;
constexpr ll lastThree = 1000;

int main() {

    ll n;
    scanf("%lld", &n);
    __int128 result = 1;

    for (ll i = 1; i <= n; ++i) {
        result *= i;
        while (result % 10 == 0) {
            result /= 10;
        }
        result %= MOD;
    }
    ll output = static_cast<ll>(result % lastThree);
    if (n <= 6) {
        printf("%lld\n", output);
    } else {
        string s = to_string(output);
        int leading_zeroes = 3 - static_cast<int>(s.size());
        printf("%s%s\n", string(leading_zeroes, '0').c_str(), s.c_str());
    }

    return 0;
}

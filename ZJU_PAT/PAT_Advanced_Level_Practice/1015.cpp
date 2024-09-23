#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(ll a) {
    if (a <= 1) return false;
    ll i;
    for (i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

ll conv(ll n, ll radix) {
    string res;
    if (n == 0) {
        return 0;
    }
    while (n > 0) {
        res += to_string(n % radix);
        n /= radix;
    }
    return stol(res, nullptr, radix);
}

int main() {
    ll n, radix, nRev;
    while (true) {
        scanf("%lld", &n);
        if (n < 0) {
            break;
        }
        scanf("%lld", &radix);
        nRev = conv(n, radix);
        if (isPrime(n) && isPrime(nRev)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
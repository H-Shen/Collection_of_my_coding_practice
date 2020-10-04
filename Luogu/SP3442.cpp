#include <iostream>
using namespace std;
using ll = long long;

const ll MOD = 10;

ll modpow(ll a, ll p, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}

int main() {
    int n;
    cin >> n;
    ll a, b;
    while (n--) {
        cin >> a >> b;
        cout << modpow(a, b, MOD) << '\n';
    }
    return 0;
}
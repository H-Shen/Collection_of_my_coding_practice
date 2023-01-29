// https://open.kattis.com/problems/ordinaryordinals
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

// (5*2^(n-1)-1)%m
// (5*2^(n-1)+(m-1))%m
// (5*2^(n-1)%m + (m-1)%m) % m
// 5*2^(n-1)%m = (5%m)*(2^(n-1)%m)%m

ull multmod(ull a, ull b, ull m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return (a % m) * (b % m) % m;
}

// O(logb), better version
ull powmod(ull a, ull b, ull m) {
    if (m == 1) return 0;
    ull r;
    for (r = 1, a %= m; b; a = multmod(a, a, m), b >>= 1) {
        if (b % 2) r = multmod(r, a, m);
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ull n, m;
    cin >> n >> m;
    if (n == 0) {
        cout << 2ULL % m << '\n';
        return 0;
    }
    cout << ((5 % m) * powmod(2, n-1, m) % m + (m-1)%m) % m << '\n';
    return 0;
}

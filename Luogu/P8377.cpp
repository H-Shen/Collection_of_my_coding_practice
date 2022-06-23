#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll MOD = 9;
constexpr int N = 1e6+5;
ll s[N];

int main() {
    // 数位和模 9 的余数和直接模 9 的余数相同
    s[1] = 1;
    s[2] = 1 + 1;
    ll a = 1;
    ll b = 1;
    ll temp;
    for (int i = 3; i < N; ++i) {
        temp = b;
        b = (a + b) % MOD;
        a = temp;
        s[i] = (s[i-1] + b) % MOD;
    }
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << s[n] << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAX = 25;

ll f[MAX];

ll factorial(const ll &n) {
    ll s = 1;
    for (ll i = 1; i <= n; i++)
        s *= i;
    return s;
}

ll combination(const ll &n, const ll &m) {
    return factorial(n) / (factorial(m) * factorial(n - m));
}

void preComputation() {
    f[0] = 0;
    f[1] = 0;
    f[2] = 1;
    for (ll i = 3; i <= 20; i++)
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    preComputation();
    ll M, N;
    while (cin >> N >> M)
        cout << combination(N, M) * f[M] << endl;
    return 0;
}
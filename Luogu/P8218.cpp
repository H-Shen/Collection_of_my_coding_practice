#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 1e5+5;
ll pre[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i-1];
    }
    cin >> m;
    int l,r;
    while (m--) {
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << '\n';
    }

    return 0;
}
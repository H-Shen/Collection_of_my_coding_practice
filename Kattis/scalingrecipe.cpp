// https://open.kattis.com/problems/scalingrecipe

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    ll x, y, a;
    cin >> n >> x >> y;
    while (n--) {
        cin >> a;
        cout << a*y/x << '\n';
    }
    return 0;
}

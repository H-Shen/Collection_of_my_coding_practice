#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // gcd(a,b) = g <= min(a, b)
    // lcm(a,b) = l
    // l * g = a * b
    int t;
    ll g, l;
    cin >> t;
    while (t--) {
        cin >> g >> l;
        if (l % g == 0) {
            cout << g << ' ' << l << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    
    return 0;
}
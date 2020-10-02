#include <bits/stdc++.h>

using namespace std;
using ll = long long;

array<ll, 6> A =
        {
                40320,
                362880,
                3628800,
                39916800,
                479001600,
                6227020800
        };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // pre
    string s;
    ll n;
    while (cin >> n) {
        if (n >= 0) {
            if (n > 13) {
                cout << "Overflow!" << '\n';
            } else if (n < 8) {
                cout << "Underflow!" << '\n';
            } else {
                cout << A.at(n - 8) << '\n';
            }
        } else {
            if (n % 2 == 0) { // -Inf
                cout << "Underflow!" << '\n';
            } else {    // Inf
                cout << "Overflow!" << '\n';
            }
        }
    }
    return 0;
}
// https://open.kattis.com/problems/modulararithmetic
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1, y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}

ll Mul(ll a, ll b, ll n) {
    return (a % n * b % n) % n;
}

ll Div(ll a, ll b, ll n) {
    if (__gcd(b, n) != 1) {
        return -1;
    }
    ll x = 0;
    ll y;
    exgcd(b, n, x, y);
    x = (x % n + n) % n;    // make sure x >= 0
    return Mul(a, x, n);
}

ll Add(ll a, ll b, ll n) {
    return (a + b) % n;
}

ll Sub(ll a, ll b, ll n) {
    return ((a - b) % n + n) % n;
}

int main() {

    ios_base::sync_with_stdio(false);
    ll n, x, y;
    string op;
    int t;
    while (true) {
        cin >> n >> t;
        if (n == 0 && t == 0) {
            break;
        }
        while (t--) {
            cin >> x >> op >> y;
            if (op == "+") {
                cout << Add(x, y, n);
            } else if (op == "-") {
                cout << Sub(x, y, n);
            } else if (op == "*") {
                cout << Mul(x, y, n);
            } else {
                cout << Div(x, y, n);
            }
            cout << endl;
        }
    }
    return 0;
}

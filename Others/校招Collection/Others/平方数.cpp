// https://ac.nowcoder.com/acm/problem/14720

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n, temp;
    cin >> n;
    ll a = static_cast<ll>(sqrt(n * 1.0)) + 1;
    while (true) {
        temp = a * a;
        if (temp <= n) {
            cout << temp << endl;
            break;
        }
        --a;
    }
    return 0;
}
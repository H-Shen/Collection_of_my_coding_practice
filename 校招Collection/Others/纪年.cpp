// https://ac.nowcoder.com/acm/problem/15749

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll year, n, gan, zhi;
    while (cin >> year) {
        n = year % 10;
        if (n > 3) {
            gan = n - 3;
        } else {
            gan = n - 3 + 10;
        }

        n = year % 12;
        if (n > 3) {
            zhi = n - 3;
        } else {
            zhi = n - 3 + 12;
        }
        cout << gan << ' ' << zhi << endl;
    }
    return 0;
}
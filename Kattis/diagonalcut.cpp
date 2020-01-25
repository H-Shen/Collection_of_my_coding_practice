// https://open.kattis.com/problems/diagonalcut
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    ll c = __gcd(a, b);

    a /= c;
    b /= c;
    if (a % 2 == 0) {
        cout << 0 << endl;
    }
    else if (b % 2 == 0) {
        cout << 0 << endl;
    }
    else {
        cout << c << endl;
    }

    return 0;
}

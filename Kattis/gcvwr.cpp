// https://open.kattis.com/problems/gcvwr

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

int main() {

    ll g, t, n;
    cin >> g >> t >> n;
    ll temp = (g - t) * 9 / 10;
    ll val;
    while (n--) {
        cin >> val;
        temp -= val;
    }
    cout << temp << '\n';

    return 0;
}

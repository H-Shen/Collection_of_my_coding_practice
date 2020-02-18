#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll x, n;
    cin >> x >> n;
    ll sum = 1;
    for (ll i = 0; i < n; ++i) {
        sum = sum + sum * x;
    }
    cout << sum << endl;

    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n, k;
    cin >> n >> k;
    ll sum = n;
    while (n >= k) {
        n -= k;
        ++sum;
        ++n;
    }
    cout << sum << endl;

    return 0;
}
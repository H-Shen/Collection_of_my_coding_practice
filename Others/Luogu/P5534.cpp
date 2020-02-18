#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll a1, a2, n, d;
    cin >> a1 >> a2 >> n;
    d = a2 - a1;
    cout << a1 * n + (n - 1) * n / 2 * d << endl;

    return 0;
}

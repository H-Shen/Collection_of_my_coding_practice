#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    ll m, n;
    cin >> n >> m;
    ll a = log2(m * 1.0);
    ++a;
    if (a > n) {
        cout << m % (ll)pow(2, n) << '\n';
    } else {
        cout << m << '\n';
    }

    return 0;
}

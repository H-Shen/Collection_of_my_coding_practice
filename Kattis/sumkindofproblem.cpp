// https://open.kattis.com/problems/sumkindofproblem

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    int t, kase;
    ll n;
    cin >> t;

    while (t--) {
        cin >> kase >> n;
        cout << kase << ' ' << (1 + n) * n / 2 << ' ' << n * n << ' ' << (1 + n) * n << endl;
    }

    return 0;
}

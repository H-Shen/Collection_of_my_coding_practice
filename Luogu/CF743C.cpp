#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll [[maybe_unused]] = long long;
using pii [[maybe_unused]] = pair<int, int>;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    ll n;
    cin >> n;
    if (n == 1) {
        cout << -1 << '\n';
    } else {
        cout << n << ' ' << n + 1 << ' ' << n*(n + 1) << '\n';
    }

    return 0;
}

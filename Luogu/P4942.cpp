#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MOD = 9;

auto fast_io = []() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {

    fast_io();
    int q;
    ll temp;
    __int128 l, r, result;
    cin >> q;
    while (q--) {
        cin >> temp;
        l = temp;
        cin >> temp;
        r = temp;
        result = (l + r) * (r - l + 1) / 2;
        cout << (int)(result % MOD) << '\n';
    }

    return 0;
}

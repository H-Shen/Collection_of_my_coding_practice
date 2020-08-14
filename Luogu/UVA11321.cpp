#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;

int n;
ll m;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline
bool cmp(const ll &l, const ll &r) {
    ll temp_l = l % m;
    ll temp_r = r % m;
    if (temp_l == temp_r) {
        bool l_is_even = false;
        bool r_is_even = false;
        if (l % 2 == 0) {
            l_is_even = true;
        }
        if (r % 2 == 0) {
            r_is_even = true;
        }
        if (l_is_even && r_is_even) {
            return r > l;
        }
        if (!l_is_even && !r_is_even) {
            return r < l;
        }
        return !l_is_even;
    }
    return (temp_l < temp_r);
}

int main() {
    fast_io();
    while (true) {
        cin >> n >> m;
        cout << n << ' ' << m << '\n';
        if (n == 0 && m == 0) {
            break;
        }
        vector<ll> A(n);
        for (auto &i : A) cin >> i;
        sort(A.begin(), A.end(), cmp);
        for (const auto &i : A) {
            cout << i << '\n';
        }
    }
    return 0;
}

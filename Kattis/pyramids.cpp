// https://open.kattis.com/problems/pyramids

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MAXN = 100000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n = 1;
    vector<ll> vec;
    vec.emplace_back(0);
    while (vec.back() < MAXN) {
        vec.emplace_back(vec.back() + n*n);
        n += 2;
    }
    ll val;
    cin >> val;
    auto iter = --upper_bound(vec.begin(),vec.end(),val);
    cout << (int)(iter - vec.begin()) << '\n';
    return 0;
}

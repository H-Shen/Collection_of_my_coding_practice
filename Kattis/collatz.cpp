// https://open.kattis.com/problems/collatz
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
tuple<ll, ll, ll> solve(ll a, ll b) {
    tuple<ll, ll, ll> ret;
    vector<int> m1;
    while (true) {
        m1.emplace_back(a);
        if (a == 1) {
            break;
        }
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = 3*a + 1;
        }
    }
    unordered_set<int> unset(m1.begin(), m1.end());
    ll b_step = 0;
    while (true) {
        if (unset.find(b) != unset.end()) {
            break;
        }
        ++b_step;
        if (b % 2 == 0) {
            b /= 2;
        } else {
            b = 3*b + 1;
        }
    }
    ll a_step = find(m1.begin(), m1.end(), b) - m1.begin();
    get<0>(ret) = a_step;
    get<1>(ret) = b_step;
    get<2>(ret) = b;

    return ret;
}

int main() {

    ll a, b;
    while (true) {
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0) {
            break;
        }
        auto p = solve(a, b);
        printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", a, get<0>(p), b, get<1>(p), get<2>(p));
    }

    return 0;
}

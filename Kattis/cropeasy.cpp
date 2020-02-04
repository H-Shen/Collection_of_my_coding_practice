// https://open.kattis.com/problems/cropeasy
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
vector<pair<ll, ll> > solve(ll n, ll x0, ll y0, ll A, ll B, ll C, ll D, ll M) {
    ll x = x0;
    ll y = y0;
    vector<pair<ll, ll> > ret;
    ret.emplace_back(make_pair(x, y));
    for (int i = 1; i <= n - 1; ++i) {
        x = (A * x + B) % M;
        y = (C * y + D) % M;
        ret.emplace_back(make_pair(x, y));
    }
    return ret;
}

int main() {

    ll t, n, x0, y0, A, B, C, D, M, x1, y1, x2, y2, x3, y3;
    scanf("%lld", &t);
    for (int kase = 1; kase <= t; ++kase) {
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &A, &B, &C, &D,
              &x0, &y0, &M);
        auto p = solve(n, x0, y0, A, B, C, D, M);
        int counter = 0;
        int length = static_cast<int>(p.size());
        for (int i = 0; i < length - 2; ++i) {
            for (int j = i + 1; j < length - 1; ++j) {
                for (int k = j + 1; k < length; ++k) {
                    x1 = p.at(i).first;
                    y1 = p.at(i).second;
                    x2 = p.at(j).first;
                    y2 = p.at(j).second;
                    x3 = p.at(k).first;
                    y3 = p.at(k).second;
                    if ((x1 + x2 + x3) % 3 == 0 && (y1 + y2 + y3) % 3 == 0) {
                        ++counter;
                    }
                }
            }
        }
        printf("Case #%d: %d\n", kase, counter);
    }


    return 0;
}

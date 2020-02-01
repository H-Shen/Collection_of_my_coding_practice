#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX = 5000005;
int op;

template<ll N, ll D = 1>
class FenwickTree {
    vector<ll> tree;

    ll isum(ll ps) { return tree[ps]; }

    template<class... T>
    ll isum(ll ps, ll n, T... tail) {
        ll a = 0;
        while (n) {
            a += isum(ps * N + n, tail...);
            n -= (n & -n);
        }
        return a;
    }

    void iupd(ll u, ll ps) { tree[ps] += u; }

    template<class... T>
    void iupd(ll u, ll ps, ll n, T... tail) {
        while (n < N) {
            iupd(u, ps * N + n, tail...);
            n += (n & -n);
        }
    }

public:
    FenwickTree() : tree(pow(N, D)) {}

    template<class... T>
    ll sum(T... v) { return isum(0, v...); }

    template<class... T>
    void upd(ll u, T... v) { iupd(u, 0, v...); }
};

int main() {

    FenwickTree<MAX> t;
    int n, query;
    ll index, value, l, r;
    scanf("%d %d", &n, &query);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &value);
        t.upd<ll>(value, i + 1);
    }
    while (query--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%lld %lld", &index, &value);
            t.upd<ll>(value, index);
        } else {
            scanf("%lld %lld", &l, &r);
            if (l > r) {
                swap(l, r);
            }
            if (l == 1) {
                printf("%lld\n", t.sum<ll>(r));
            } else {
                printf("%lld\n", t.sum<ll>(r) - t.sum<ll>(l - 1));
            }
        }
    }

    return 0;
}
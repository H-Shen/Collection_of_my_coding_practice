// https://open.kattis.com/problems/fenwick
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX = 5000005;
constexpr int MAX_STR_LEN = 3;
char op[MAX_STR_LEN];

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
    int n, k;
    ll index, value, r;
    scanf("%d %d", &n, &k);
    while (k--) {
        scanf("%s", op);
        if (strcmp(op, "+") == 0) {
            scanf("%lld %lld", &index, &value);
            t.upd<ll>(value, index + 1);
        } else {
            scanf("%lld", &r);
            if (r == 0) {
                printf("0\n");
            } else {
                printf("%lld\n", t.sum<ll>(r));
            }
        }
    }

    return 0;
}

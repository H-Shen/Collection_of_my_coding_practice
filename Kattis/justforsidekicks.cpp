// https://open.kattis.com/problems/justforsidekicks
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 200005;
constexpr int TYPES = 6;
char str[MAXN];

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

FenwickTree<MAXN> T1, T2, T3, T4, T5, T6;
vector<ll> Price(TYPES + 1);

int main() {

    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i < TYPES + 1; ++i) {
        scanf("%lld", &Price.at(i));
    }
    scanf("%s", str);
    for (int i = 0; str[i] != '\0'; ++i) {
        switch (str[i]) {
            case '1':
                T1.upd(1, i + 1);
                break;
            case '2':
                T2.upd(1, i + 1);
                break;
            case '3':
                T3.upd(1, i + 1);
                break;
            case '4':
                T4.upd(1, i + 1);
                break;
            case '5':
                T5.upd(1, i + 1);
                break;
            default:
                T6.upd(1, i + 1);
                break;
        }
    }
    int op;
    ll x;
    ll y;
    while (q--) {
        scanf("%d %lld %lld", &op, &x, &y);
        if (op == 1) {
            switch (str[x - 1]) {
                case '1':
                    T1.upd(-1, x);
                    break;
                case '2':
                    T2.upd(-1, x);
                    break;
                case '3':
                    T3.upd(-1, x);
                    break;
                case '4':
                    T4.upd(-1, x);
                    break;
                case '5':
                    T5.upd(-1, x);
                    break;
                default:
                    T6.upd(-1, x);
                    break;
            }
            str[x - 1] = static_cast<char>(y + '0');
            switch (str[x - 1]) {
                case '1':
                    T1.upd(1, x);
                    break;
                case '2':
                    T2.upd(1, x);
                    break;
                case '3':
                    T3.upd(1, x);
                    break;
                case '4':
                    T4.upd(1, x);
                    break;
                case '5':
                    T5.upd(1, x);
                    break;
                default:
                    T6.upd(1, x);
                    break;
            }
        }
        else if (op == 2) {
            Price.at(x) = y;
        }
        else {
            ll result = 0;
            if (x == 1) {
                result = T1.sum(y)*Price.at(1)+T2.sum(y)*Price.at(2)+T3.sum(y)*Price.at(3)+T4.sum(y)*Price.at(4)+T5.sum(y)*Price.at(5)+T6.sum(y)*Price.at(6);
            } else {
                result += (T1.sum(y) - T1.sum(x - 1)) * Price.at(1);
                result += (T2.sum(y) - T2.sum(x - 1)) * Price.at(2);
                result += (T3.sum(y) - T3.sum(x - 1)) * Price.at(3);
                result += (T4.sum(y) - T4.sum(x - 1)) * Price.at(4);
                result += (T5.sum(y) - T5.sum(x - 1)) * Price.at(5);
                result += (T6.sum(y) - T6.sum(x - 1)) * Price.at(6);
            }
            printf("%lld\n", result);
        }
    }
    return 0;
}

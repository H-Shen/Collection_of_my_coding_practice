// https://ac.nowcoder.com/acm/problem/14519

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline static
ll gcd(ll a, ll b) { return (b > 0) ? gcd(b, a % b) : a; }

struct frac {
    ll m{}, n{};
    bool isNeg = false;

    frac(ll a, ll b) : m(a), n(b) { simplify(); }

    frac() = default;

    void simplify();
};

inline
void frac::simplify() {
    ll tmp = gcd(m, n);
    m /= tmp;
    n /= tmp;
}

inline
frac operator+(frac a, frac b) {
    frac res;
    res.m = a.m * b.n + b.m * a.n;
    res.n = a.n * b.n;
    if (res.m == 0) {
        res.n = 1;
    } else if (res.m % res.n == 0) {
        res.m /= res.n;
        res.n = 1;
    } else {
        res.simplify();
    }
    return res;
}

inline
frac operator-(frac a, frac b) {
    frac res;
    res.m = a.m * b.n - b.m * a.n;
    res.n = a.n * b.n;
    if (res.m < 0) {
        res.m = -res.m;
        res.isNeg = true;
    }
    if (res.m == 0) {
        res.n = 1;
    } else if (res.m % res.n == 0) {
        res.m /= res.n;
        res.n = 1;
    } else {
        res.simplify();
    }
    return res;
}

inline static
string repr(frac a) {
    string res;
    if (a.isNeg) {
        res += '-';
    }
    res += to_string(a.m) + '/' + to_string(a.n);
    return res;
}

int main() {
    int n, op;
    ll a, b, c, d;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %lld %lld %lld %lld", &op, &a, &b, &c, &d);
        frac A(a, b);
        frac B(c, d);
        frac C;
        if (op == 1) {
            C = A + B;
        } else {
            C = A - B;
        }
        printf("%s\n", repr(C).c_str());
    }
    return 0;
}
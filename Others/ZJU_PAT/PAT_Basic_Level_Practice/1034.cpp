#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct frac {
    bool isNeg{};
    ll m{}, n{};
    bool isLegal{true};
};

string repr(frac A) {
    if (!A.isLegal) {
        return "Inf";
    }
    string res;
    if (A.n == 1) {
        res = to_string(A.m);
    } else {

        ll a = 0, tmp;
        bool have_a = false;

        if (A.m > A.n) {
            a = A.m / A.n;
            A.m = A.m % A.n;
#ifdef __GNUC__
            tmp = __gcd(A.m, A.n);
#endif
            A.m /= tmp;
            A.n /= tmp;
            have_a = true;
        }

        if (have_a) {
            res += to_string(a) + ' ' + to_string(A.m) + '/' + to_string(A.n);
        } else if (A.n == 1) {
            res += to_string(A.m);
        } else {
            res += to_string(A.m) + '/' + to_string(A.n);
        }
    }

    if (A.isNeg) {
        res = "(-" + res + ')';
    }

    return res;
}

void parse(const string &s, ll &m, ll &n, bool &isNeg) {
    int i = 0;
    int len = static_cast<int>(s.size());

    if (s[0] == '-') {
        isNeg = true;
        ++i;
    } else {
        isNeg = false;
    }

    string first, second;
    bool delimiter = false;
    for (; i < len; ++i) {
        if (delimiter) {
            second += s[i];
        } else if (s[i] == '/') {
            delimiter = true;
        } else {
            first += s[i];
        }
    }

    m = stol(first);
    n = stol(second);
}

void simplify(frac &A) {
    ll m, n;

    if (A.m == 0) {
        A.n = 1;
        A.isNeg = false;
        return;
    }

    if (A.m < 0) {
        m = -A.m;
    } else {
        m = A.m;
    }
    if (A.n < 0) {
        n = -A.n;
    } else {
        n = A.n;
    }

    ll tmp = __gcd(m, n);
    A.m /= tmp;
    A.n /= tmp;

}

frac operator+(frac A, frac B) {
    if (A.isNeg) {
        A.m = -A.m;
    }
    if (B.isNeg) {
        B.m = -B.m;
    }
    frac res;
    res.n = A.n * B.n;
    res.m = A.m * B.n + A.n * B.m;

    if (res.m < 0) {
        res.isNeg = true;
        res.m = -res.m;
    } else {
        res.isNeg = false;
    }

    simplify(res);
    return res;
}

frac operator-(frac A, frac B) {
    B.isNeg = !B.isNeg;
    frac res = A + B;
    return res;
}

frac operator*(frac A, frac B) {
    frac res;
    if (A.isNeg && B.isNeg) {
        res.isNeg = false;
    } else if (!A.isNeg) {
        res.isNeg = B.isNeg;
    } else {
        res.isNeg = true;
    }
    res.m = A.m * B.m;
    res.n = A.n * B.n;
    simplify(res);
    return res;
}

frac operator/(frac A, frac B) {
    frac res;
    if (B.m == 0) {
        res.isLegal = false;
        return res;
    }
    if (A.isNeg && B.isNeg) {
        res.isNeg = false;
    } else if (!A.isNeg) {
        res.isNeg = B.isNeg;
    } else {
        res.isNeg = true;
    }
    res.m = A.m * B.n;
    res.n = A.n * B.m;
    simplify(res);
    return res;
}

int main() {

    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    frac a_frac, b_frac, c_frac;

    parse(a, a_frac.m, a_frac.n, a_frac.isNeg);
    simplify(a_frac);

    parse(b, b_frac.m, b_frac.n, b_frac.isNeg);
    simplify(b_frac);

    c_frac = a_frac + b_frac;
    cout << repr(a_frac) << " + " << repr(b_frac) << " = " << repr(c_frac) << endl;

    c_frac = a_frac - b_frac;
    cout << repr(a_frac) << " - " << repr(b_frac) << " = " << repr(c_frac) << endl;

    c_frac = a_frac * b_frac;
    cout << repr(a_frac) << " * " << repr(b_frac) << " = " << repr(c_frac) << endl;

    c_frac = a_frac / b_frac;
    cout << repr(a_frac) << " / " << repr(b_frac) << " = " << repr(c_frac) << endl;

    return 0;
}
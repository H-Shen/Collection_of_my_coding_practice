#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return (b > 0) ? gcd(b, a % b) : a; }

struct frac {
    ll m, n;
    bool isNeg;
};

frac operator+(frac a, frac b) {
    if (a.isNeg) a.m = -a.m;
    if (b.isNeg) b.m = -b.m;

    frac res;
    res.m = a.m * b.n + b.m * a.n;
    res.n = a.n * b.n;

    if (res.m == 0) {
        res.n = 1;
        res.isNeg = false;
        return res;
    }

    if (res.m < 0) {
        res.m = -res.m;
        res.isNeg = true;
    }
    else { res.isNeg = false; }

    if (res.m % res.n == 0) {
        res.m /= res.n;
        res.n = 1;
    }
    else {
        ll tmp = gcd(res.m, res.n);
        res.m /= tmp;
        res.n /= tmp;
    }

    return res;
}

string repr(frac a) {
    string res;
    if (a.n == 1) { res = res + to_string(a.m); }
    else if (a.m < a.n) { res = res + to_string(a.m) + '/' + to_string(a.n); }
    else {

        ll A = a.m / a.n;
        a.m = a.m % a.n;

        ll tmp = gcd(a.m, a.n);
        a.m /= tmp;
        a.n /= tmp;

        res = res + to_string(A) + ' ' + to_string(a.m) + '/' + to_string(a.n);
    }
    if (a.isNeg) {
        res = "-" + res;
    }
    return res;
}

frac parse(string a) {
    int len = a.size();
    int i;
    string part0, part1;
    bool split = false;

    frac res;
    res.isNeg = false;
    for (i = 0; i < len; ++i) {
        if (i == 0 && a[i] == '-') {
            res.isNeg = true;
            continue;
        }
        if (!split && a[i] == '/') {
            split = true;
            continue;
        }
        if (!split) {
            part0 += a[i];
        } else {
            part1 += a[i];
        }
    }
    res.m = stol(part0);
    res.n = stol(part1);

    ll tmp = gcd(res.m, res.n);
    res.m /= tmp;
    res.n /= tmp;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    frac sum = parse("0/1");
    for (int i = 0; i < n; ++i) {
        cin >> s;
        sum = sum + parse(s);
    }
    cout << repr(sum) << endl;
    return 0;
}
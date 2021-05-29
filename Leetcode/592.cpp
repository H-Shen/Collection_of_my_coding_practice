using ll = long long;

struct Frac {
    ll n, d;
    bool isNeg;
    Frac() = default;
    Frac(string s) {
        isNeg = (s[0] == '-');
        s = s.substr(1);
        sscanf(s.c_str(), "%ld/%ld", &n, &d);
    }
    string toString() const {
        string res;
        if (isNeg) {
            res.push_back('-');
        }
        res += to_string(n);
        res.push_back('/');
        res += to_string(d);
        return res;
    }
};

Frac add(Frac l, Frac r) {
    if (l.isNeg) {
        l.n = -l.n;
    }
    if (r.isNeg) {
        r.n = -r.n;
    }
    Frac res;
    res.n = l.n*r.d+l.d*r.n;
    res.d = l.d*r.d;
    if (res.n < 0) {
        res.isNeg = true;
        res.n = -res.n;
    } else {
        res.isNeg = false;
    }
    ll g = gcd(res.n, res.d);
    res.n /= g;
    res.d /= g;
    return res;
}

class Solution {
public:
    string fractionAddition(string expression) {
        if (expression[0] != '-') {
            expression = '+' + expression;
        }
        Frac res;
        res.isNeg = false;
        res.n = 0;
        res.d = 1;
        static const regex r("(\\+|\\-)[0-9]+/[0-9]+");
        for (sregex_iterator it(expression.begin(), expression.end(), r), end_it; it != end_it; ++it) {
            res = add(res, Frac(it->str()));
        }
        return res.toString();
    }
};
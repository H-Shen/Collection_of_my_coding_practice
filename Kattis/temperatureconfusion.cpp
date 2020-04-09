// https://open.kattis.com/problems/temperatureconfusion
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Fraction {
    ll a, b;
    bool isNeg;
    Fraction(ll a, ll b) {
        if (a == 0) {
            this->a = 0;
            this->b = 1;
            isNeg = false;
            return;
        } else {
            isNeg = a * b < 0;
        }
        this->a = abs(a);
        this->b = abs(b);
        ll temp = __gcd(this->a, this->b);
        this->a /= temp;
        this->b /= temp;
    }

    friend ostream &operator<<(ostream &os, const Fraction &fraction) {
        os << ((fraction.isNeg) ? "-" : "" ) << fraction.a << "/" << fraction.b;
        return os;
    }
};

int main() {

    ll a, b;
    scanf("%lld/%lld", &a, &b);
    cout << Fraction(5 * a - 160 * b, 9 * b) << endl;
    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Fraction {
    ll x, y;
    bool is_negative;
    explicit Fraction(ll x, ll y) {
        if (x == 0) {
            this->x = 0;
            this->y = 1;
            is_negative = false;
        } else {
            is_negative = x * y < 0;
            this->x = abs(x);
            this->y = abs(y);
            ll temp = __gcd(this->x, this->y);
            this->x /= temp;
            this->y /= temp;
        }
    }
};

int main() {
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    Fraction f(a * c, b * d);
    printf("%lld %lld\n", f.y, f.x);
    return 0;
}

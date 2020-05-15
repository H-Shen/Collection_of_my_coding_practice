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
    [[nodiscard]] string to_string() const {
        string result;
        if (x == 0) {
            return result;
        }
        if (is_negative) {
            result.push_back('-');
        }
        result += ::to_string(x);
        if (y != 1) {
            result.push_back('/');
            result += ::to_string(y);
        }
        return result;
    }
};

inline
Fraction operator + (Fraction A, Fraction B) {
    if (A.is_negative) {
        A.x = -A.x;
    }
    if (B.is_negative) {
        B.x = -B.x;
    }
    return Fraction(A.x * B.y + A.y * B.x, A.y * B.y);
}

inline regex r("(\\+|\\-){0,1}[0-9]+/[0-9]+");
constexpr int MAXN = 150;
char input_buffer[MAXN];

int main() {
    
    fread(input_buffer, sizeof(char), MAXN, stdin);
    string s(input_buffer);
    ll x, y;
    vector<Fraction> A;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
         it != end_it; ++it) {
        sscanf(it->str().c_str(), "%lld/%lld", &x, &y);
        A.emplace_back(Fraction(x, y));
    }
    Fraction sum(0, 1);
    for (const auto &i : A) {
        sum = sum + i;
    }
    printf("%s\n", sum.to_string().c_str());

    return 0;
}
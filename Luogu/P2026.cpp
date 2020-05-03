#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

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
        } else {
            result.push_back('+');
        }
        result += ::to_string(x);
        if (y != 1) {
            result.push_back('/');
            result += ::to_string(y);
        }
        return result;
    }
};

int main() {
    ll x1, y1, x2, y2;
    IO::read(x1, y1, x2, y2);
    if (x1 == x2) {
        printf("x=%lld\n", x1);
    } else {
        Fraction a(y2 - y1, x2 - x1);
        Fraction b((y1 - y2)*x1+y1*(x2-x1), x2-x1);
        string a_str = a.to_string();
        string b_str = b.to_string();
        printf("y=");
        if (a_str.empty()) {
            if (b_str.empty()) {
                printf("0\n");
            } else {
                if (b_str.front() == '+') {
                    b_str = b_str.substr(1);
                }
                printf("%s\n", b_str.c_str());
            }
        } else {
            if (a_str.front() == '+') {
                a_str = a_str.substr(1);
            }
            if (!(a.x == 1 && a.y == 1)) {
                printf("%s", a_str.c_str());
            }
            if (count(a_str.begin(), a_str.end(), '/') > 0) {
                printf("*x");
            } else {
                printf("x");
            }
            if (b_str.empty()) {
                printf("\n");
            } else {
                printf("%s\n", b_str.c_str());
            }
        }
    }
    return 0;
}
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
inline
void read(T& t) {
    int n = 0; int c = getchar(); t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (n) t = -t;
}
template <typename T, typename... Args>
inline
void read(T& t, Args&... args) {
    read(t); read(args...);
}

template <typename T>
inline void write(T x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
    write(x);
    puts("");
}

using ll = long long;
vector<ll> powerOfNine = {1,
                          9,
                          81,
                          729,
                          6561,
                          59049,
                          531441,
                          4782969,
                          43046721,
                          387420489,
                          3486784401,
                          31381059609};

int main() {

    int t;
    ll n;
    ll digit;
    ll result;
    int counter;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);
        result = 0;
        counter = 0;
        while (n > 0) {
            digit = n % 10;
            if (digit >= 7) {
                result += (digit - 1) * powerOfNine.at(counter);
            } else {
                result += digit * powerOfNine.at(counter);
            }
            n /= 10;
            ++counter;
        }
        printf("%lld\n", result);
    }

    return 0;
}
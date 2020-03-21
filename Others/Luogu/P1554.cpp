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
constexpr int MAXN = 10;
array<ll, MAXN> stats;

int main() {

    ll m, n, copy;
    scanf("%lld %lld", &m, &n);
    for (ll i = m; i <= n; ++i) {
        copy = i;
        while (copy > 0) {
            ++stats.at(copy % 10);
            copy /= 10;
        }
    }
    bool first_item = true;
    for (int i = 0; i < MAXN; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%lld", stats.at(i));
    }
    printf("\n");

    return 0;
}
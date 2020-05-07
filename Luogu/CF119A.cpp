#include <bits/stdc++.h>

using namespace std;

#define CODEFORCES

#ifdef CODEFORCES
namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = _getchar_nolock(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = _getchar_nolock();
        while (isdigit(c)) t = t * 10 + c - 48, c = _getchar_nolock();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, _putchar_nolock('-');
        if (x > 9) write(x / 10);
        _putchar_nolock(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        _putchar_nolock('\n');
    }
}
#else
namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}
#endif

constexpr int MAXN = 105;
int store_gcd[MAXN][MAXN];

int my_gcd(int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    if (store_gcd[m][n] > 0) {
        return store_gcd[m][n];
    }
    int temp = my_gcd(n, m % n);
    store_gcd[m][n] = temp;
    store_gcd[n][m] = temp;
    return temp;
}

int a, b, n;

int main() {

    IO::read(a, b, n);
    while (true) {
        n -= my_gcd(n, a);
        if (n <= 0) {
            IO::writeln(0);
            break;
        }
        n -= my_gcd(n, b);
        if (n <= 0) {
            IO::writeln(1);
            break;
        }
    }

    return 0;
}

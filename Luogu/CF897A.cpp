#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define CODEFORCES

#ifdef CODEFORCES
namespace IO {
    inline void read_letters(char &t) {
        t = _getchar_nolock();
        while (!isalpha(t)) {
            t = _getchar_nolock();
        }
    }
    template<typename ... Args>
    inline void read_letters(char &t, Args & ... args) {
        read_letters(t);
        read_letters(args...);
    }
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
    inline void read_letters(char &t) {
        t = getchar_unlocked();
        while (!isalpha(t)) {
            t = getchar_unlocked();
        }
    }
    template<typename ... Args>
    inline void read_letters(char &t, Args & ... args) {
        read_letters(t);
        read_letters(args...);
    }

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
char s[MAXN];
int n, m, l, r;
char c1, c2;

int main() {

    IO::read(n, m);
    scanf("%s", s + 1); // start from index = 1
    while (m--) {
        IO::read(l, r);
        IO::read_letters(c1, c2);
        for (int i = l; i <= r; ++i) {
            if (s[i] == c1) {
                s[i] = c2;
            }
        }
    }
    fputs(s + 1, stdout);
    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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


int five;
int zero;
int n;
int val;

int main() {

    IO::read(n);
    while (n--) {
        IO::read(val);
        if (val == 5) {
            ++five;
        } else {
            ++zero;
        }
    }
    if (zero > 0) {
        if (five >= 9) {
            fputs(string(five / 9 * 9, '5').c_str(), stdout);
            fputs(string(zero, '0').c_str(), stdout);
        } else {
            fputs("0", stdout);
        }
    } else {
        fputs("-1", stdout);
    }

    return 0;
}

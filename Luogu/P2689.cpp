#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

int main() {

    int i0, j0, i1, j1, m;
    int moves = 0;
    char dir;
    IO::read(i0, j0, i1, j1, m);
    while (m--) {
        IO::read_letters(dir);
        switch (dir) {
            case 'N':
                if (i0 < i1) {
                    ++i0;
                    ++moves;
                }
                break;
            case 'S':
                if (i0 > i1) {
                    --i0;
                    ++moves;
                }
                break;
            case 'W':
                if (j0 > j1) {
                    --j0;
                    ++moves;
                }
                break;
            case 'E':
                if (j0 < j1) {
                    ++j0;
                    ++moves;
                }
                break;
        }
    }
    if (i0 == i1 && j0 == j1) {
        IO::writeln(moves);
    } else {
        IO::writeln(-1);
    }

    return 0;
}

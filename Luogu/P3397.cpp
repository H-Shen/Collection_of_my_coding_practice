// 2d diff array

#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }

    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
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

constexpr int MAXN = 1005;
int diff[MAXN][MAXN];
int n, m;

int main() {

    IO::read(n, m);
    int x1, y1, x2, y2; // index starts from 1
    while (m--) {
        IO::read(x1, y1, x2, y2);
        // +c ---- o -c
        //  |      |
        //  |      |
        //  |      |
        //  o ---- o ---
        // -c      | +c
        ++diff[x1][y1];
        --diff[x2+1][y1];
        --diff[x1][y2+1];
        ++diff[x2+1][y2+1];
    }
    // restore to the prefixsum
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            diff[i][j] = diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1] + diff[i][j];
        }
    }
    // output
    bool firstItem;
    for (int i = 1; i <= n; ++i) {
        firstItem = true;
        for (int j = 1; j <= n; ++j) {
            if (firstItem) {
                firstItem = false;
            } else {
                putchar_unlocked(' ');
            }
            IO::write(diff[i][j]);
        }
        putchar_unlocked('\n');
    }

    return 0;
}

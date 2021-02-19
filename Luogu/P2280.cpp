#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

constexpr int MAXN = 5010;
short pre[MAXN][MAXN];
short A[MAXN][MAXN];

short rangeSum(int r0, int c0, int r1, int c1) {
    if (r0 == 0 && c0 == 0) return pre[r1][c1];
    else if (r0 == 0 && c0 != 0) return pre[r1][c1] - pre[r1][c0 - 1];
    else if (r0 != 0 && c0 == 0) return pre[r1][c1] - pre[r0 - 1][c1];
    return pre[r1][c1] - pre[r0 - 1][c1] - pre[r1][c0 - 1] + pre[r0 - 1][c0 - 1];
}

int main() {

    int n, m, r, c;
    short temp;
    IO::read(n, m);
    for (int i = 0; i < n; ++i) {
        IO::read(r, c);
        IO::read(A[r][c]);
    }

    pre[0][0] = A[0][0];
    for (int i = 1; i < MAXN; ++i)
        pre[0][i] = pre[0][i - 1] + A[0][i];
    for (int i = 1; i < MAXN; ++i)
        pre[i][0] = pre[i - 1][0] + A[i][0];
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j)
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + A[i][j];
    }

    short maxVal = 0;
    for (int i = 0; i + m - 1 < MAXN; ++i) {
        for (int j = 0; j + m - 1 < MAXN; ++j) {
            maxVal = max(maxVal, rangeSum(i, j, i + m - 1, j + m - 1));
        }
    }
    IO::writeln(maxVal);

    return 0;
}
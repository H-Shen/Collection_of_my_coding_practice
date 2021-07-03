// https://open.kattis.com/problems/shortsell

#include <bits/stdc++.h>

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

constexpr int COUNT = 100;
int n, k, val;
vector<int> B, maxFromLeft, minFromRight;

int main() {

    IO::read(n, k);
    if (n == 1) return 0;
    B.resize(n);
    for (int i = 0; i < n; ++i) {
        IO::read(val);
        B[i] = COUNT*val+k*i;
    }
    maxFromLeft.resize(n);
    maxFromLeft[0] = B[0];
    for (int i = 1; i < n; ++i) {
        maxFromLeft[i] = max(maxFromLeft[i], B[i]);
    }
    minFromRight.resize(n);
    minFromRight[n-1] = B[n-1];
    for (int i = n-2; i >= 0; --i) {
        minFromRight[i] = min(minFromRight[i+1], B[i]);
    }
    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        ans = max(ans, maxFromLeft[i] - minFromRight[i+1] - k);
    }
    IO::writeln(ans);

    return 0;
}

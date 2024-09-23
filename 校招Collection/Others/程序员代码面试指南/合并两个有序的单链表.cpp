// https://www.nowcoder.com/practice/98a51a92836e4861be1803aaa9037440

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000005;
array<int, MAXN> A;

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

int main() {
    int n, m;
    IO::read(n);
    for (int i = 0; i < n; ++i) {
        IO::read(A.at(i));
    }
    IO::read(m);
    int total = n + m;
    for (int i = n; i < total; ++i) {
        IO::read(A.at(i));
    }
    inplace_merge(A.begin(), A.begin() + n, A.begin() + total);
    if (total > 0) {
        IO::write(A.front());
    }
    for (int i = 1; i < total; ++i) {
        putchar_unlocked(' ');
        IO::write(A.at(i));
    }
    putchar_unlocked('\n');
    return 0;
}
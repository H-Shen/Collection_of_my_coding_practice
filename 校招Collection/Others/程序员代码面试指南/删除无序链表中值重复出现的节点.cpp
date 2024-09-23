// https://www.nowcoder.com/practice/fb3105d036344c6a8ecbef996e0b23a0

#include <bits/stdc++.h>

using namespace std;

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

constexpr int MAXN = 2000005;
constexpr int GAP = 1000000;
bitset<MAXN> vis;
forward_list<int> A;

int main() {

    int n, val, offset;
    IO::read(n);
    auto it = A.before_begin();
    for (int i = 0; i < n; ++i) {
        IO::read(val);
        offset = val + GAP;
        if (!vis[offset]) {
            it = A.emplace_after(it, val);
            vis[offset] = true;
        }
    }
    bool firstItem = true;
    for (const int &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            putchar_unlocked(' ');
        }
        IO::write(i);
    }
    return 0;
}
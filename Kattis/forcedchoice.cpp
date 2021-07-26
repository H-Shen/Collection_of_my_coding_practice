// https://open.kattis.com/problems/forcedchoice

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

int n, p, s, m;

int main() {
    IO::read(n, p, s);
    vector<vector<int> > cards(s);
    for (auto &i : cards) {
        IO::read(m);
        i.resize(m);
        for (auto &j : i) {
            IO::read(j);
        }
        sort(i.begin(), i.end());
    }
    vector<bool> ans(s);
    for (int i = s - 1; i >= 0; --i) {
        if (binary_search(cards[i].begin(), cards[i].end(), p)) {
            ans[i] = true;
        }
    }
    for (const auto &i : ans) {
        if (i) puts("KEEP");
        else puts("REMOVE");
    }

    return 0;
}

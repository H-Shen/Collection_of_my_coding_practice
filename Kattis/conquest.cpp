// https://open.kattis.com/problems/conquest

#include <bits/stdc++.h>

using namespace std;

namespace IO {
    template <typename T>
    inline void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n)
            t = -t;
    }

    template <typename T, typename... Args>
    inline void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template <typename T>
    inline void write(T x) {
        if (x < 0)
            x = -x, putchar_unlocked('-');
        if (x > 9)
            write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr int MAXN = 200005;
vector<int> AL[MAXN];
int A[MAXN];
int B[MAXN];
int n,m;

int main() {

    IO::read(n,m);
    int u,v;
    while (m--) {
        IO::read(u, v);
        u--; v--;
        AL[u].emplace_back(v);
        AL[v].emplace_back(u);
    }
    for (int i = 0; i < n; ++i) IO::read(B[i]);
    int ans = B[0];
    A[0] = 1;
    set<pair<int,int>> s;
    for (const auto &i : AL[0]) {
        s.insert({B[i], i});
    }
    pair<int,int> temp;
    while (!s.empty()) {
        temp = *s.begin();
        s.erase(s.begin());
        A[temp.second] = 1;
        if (temp.first >= ans) break;
        ans += temp.first;
        for (const auto &i : AL[temp.second]) {
            if (A[i] == 0) s.insert({B[i], i});
        }
    }
    IO::writeln(ans);
    return 0;
}

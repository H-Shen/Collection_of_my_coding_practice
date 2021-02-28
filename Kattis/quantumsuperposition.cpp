// https://open.kattis.com/problems/quantumsuperposition

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

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

int n1, n2, m1, m2;
vector<int> out_degree_1, out_degree_2;
vector<bitset<MAXN> > dp1, dp2;
bitset<MAXN> dp1vis, dp2vis;
vector<vector<int> > adj_rev_1, adj_rev_2;

bitset<MAXN> solve1(int v) {
    if (dp1vis[v]) return dp1[v];
    for (const auto &u : adj_rev_1.at(v)) { // (u,v) \in E
        if (!dp1vis[v]) {
            dp1vis[v] = true;
            dp1[v] = solve1(u) << 1;
        } else {
            dp1[v] |= (solve1(u) << 1);
        }
    }
    return dp1[v];
}

bitset<MAXN> solve2(int v) {
    if (dp2vis[v]) return dp2[v];
    for (const auto &u : adj_rev_2.at(v)) { // (u,v) \in E
        if (!dp2vis[v]) {
            dp2vis[v] = true;
            dp2[v] = solve2(u) << 1;
        } else {
            dp2[v] |= (solve2(u) << 1);
        }
    }
    return dp2[v];
}


int main() {

    int u, v;
    IO::read(n1, n2, m1, m2);
    adj_rev_1.resize(n1 + 1);
    adj_rev_2.resize(n2 + 1);
    out_degree_1.resize(n1 + 1);
    out_degree_2.resize(n2 + 2);
    dp1.resize(n1 + 1);
    dp2.resize(n2 + 1);

    dp1[1] = 1;
    dp1vis[1] = true;
    dp2[1] = 1;
    dp2vis[1] = true;


    for (int i = 0; i < m1; ++i) {
        IO::read(u, v);
        adj_rev_1.at(v).emplace_back(u);
        ++out_degree_1.at(u);
    }
    for (int i = 0; i < m2; ++i) {
        IO::read(u, v);
        adj_rev_2.at(v).emplace_back(u);
        ++out_degree_2.at(u);
    }
    bitset<MAXN> g1;
    bool g1_init = false;
    for (int i = 1; i <= n1; ++i) {
        if (out_degree_1.at(i) == 0) {
            if (!g1_init) {
                g1_init = true;
                g1 = solve1(i);
            } else {
                g1 |= solve1(i);
            }
        }
    }
    bitset<MAXN> g2;
    bool g2_init = false;
    for (int i = 1; i <= n2; ++i) {
        if (out_degree_2.at(i) == 0) {
            if (!g2_init) {
                g2_init = true;
                g2 = solve2(i);
            } else {
                g2 |= solve2(i);
            }
        }
    }
    bitset<MAXN << 1> bsum;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            if (g1[i] && g2[j]) {
                bsum[i + j] = true;
            }
        }
    }
    int q, sum;
    IO::read(q);
    while (q--) {
        IO::read(sum);
        if (bsum[sum]) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}

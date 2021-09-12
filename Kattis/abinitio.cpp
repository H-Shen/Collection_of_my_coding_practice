// https://open.kattis.com/problems/abinitio

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

constexpr int MAXN = 5005;
constexpr ll MOD = 1e9+7;

vector<bool> outDegree[MAXN];
vector<bool> inDegree[MAXN];
ll Pow[MAXN];

int n, e, q, u, v, op;

void pre() {
    Pow[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        Pow[i] = (Pow[i-1]*7LL) % MOD;
    }
}

int main() {
    IO::read(n, e, q);
    for (int i = 0; i < n; ++i) {
        outDegree[i].resize(n);
        inDegree[i].resize(n);
    }
    while (e--) {
        IO::read(u,v);
        inDegree[v][u] = true;
        outDegree[u][v] = true;
    }
    while (q--) {
        IO::read(op);
        switch (op) {
            case 1:
                for (int i = 0; i < n; ++i) {
                    outDegree[i].emplace_back(false);
                    inDegree[i].emplace_back(false);
                }
                outDegree[n].resize(n+1);
                inDegree[n].resize(n+1);
                ++n;
                break;
            case 2:
                IO::read(u,v);
                outDegree[u][v] = true;
                inDegree[v][u] = true;
                break;
            case 3:
                IO::read(u);
                fill(outDegree[u].begin(),outDegree[u].end(), false);
                fill(inDegree[u].begin(),inDegree[u].end(), false);
                for (int i = 0; i < n; ++i) {
                    outDegree[i][u] = false;
                    inDegree[i][u] = false;
                }
                break;
            case 4:
                IO::read(u, v);
                outDegree[u][v] = false;
                inDegree[v][u] = false;
                break;
            case 5:
                for (int i = 0; i < n; ++i) {
                    inDegree[i].swap(outDegree[i]);
                }
                break;
            case 6:
                for (int i = 0; i < n; ++i) {
                    inDegree[i].flip();
                    inDegree[i][i] = false;
                    outDegree[i].flip();
                    outDegree[i][i] = false;
                }
                break;
        }
    }
    // output
    pre();
    IO::writeln(n);
    ll h;
    int counter;
    for (int i = 0; i < n; ++i) {
        h = 0;
        counter = 0;
        for (int j = 0; j < n; ++j) {
            if (outDegree[i][j]) {
                h = (h + Pow[counter]*j) % MOD;
                ++counter;
            }
        }
        IO::write(counter);
        putchar_unlocked(' ');
        IO::writeln(h);
    }
    return 0;
}

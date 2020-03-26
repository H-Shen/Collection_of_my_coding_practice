// https://open.kattis.com/problems/airports
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 505;

int n, m;
int t[MAXN];
int M[MAXN][MAXN];
int F[MAXN][MAXN];
pair<int, int> A[MAXN], B[MAXN];
vector<int> G[MAXN];

int Left[MAXN];
int vis[MAXN];

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

bool check(int u) {
    for (size_t i = 0; i != G[u].size(); ++i) {
        int v = G[u][i];
        if (!vis[v]) {
            vis[v] = 1;
            if (Left[v] == -1 || check(Left[v])) {
                Left[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main() {

    IO::read(n, m);
    for (int i = 1; i <= n; ++i) {
        IO::read(t[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            IO::read(M[i][j]);
            if (i != j) {
                M[i][j] += t[j];
            }
        }
    }
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            F[i][j] = M[i][j];
        }
    }
    // Floyd
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                F[i][j] = min(F[i][j], F[i][k] + F[k][j]);
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v, time;
        IO::read(u, v, time);
        A[i] = {u, time};
        B[i] = {v, time + M[u][v]};
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            if (i != j &&
                B[i].second + F[B[i].first][A[j].first] <= A[j].second) {
                G[i].push_back(j);
            }
        }
    }
    memset(Left, -1, sizeof(Left));
    int result = 0;
    for (int i = 1; i <= m; i++) {
        memset(vis, 0, sizeof(vis));
        if (check(i)) {
            ++result;
        }
    }
    IO::writeln(m - result);
    
    return 0;
}

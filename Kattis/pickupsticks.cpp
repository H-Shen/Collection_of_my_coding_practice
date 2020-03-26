// https://open.kattis.com/problems/pickupsticks
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 1000005;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        puts("");
    }
}

unordered_map<int, unordered_set<int> > E;
int in_deg[MAXN]; // the number of incoming edges of each node
int n, m;
int answer[MAXN];
int counter = 0;

inline static
bool toposort() {
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (in_deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        answer[counter++] = u;
        for (const auto &v : E[u]) {
            --in_deg[v];
            if (in_deg[v] == 0) {
                q.push(v);
            }
        }
    }
    return (counter == n);
}

int main() {

    IO::read(n, m);
    int u, v;
    while (m--) {
        IO::read(u, v);
        if (E.find(u) == E.end() || E[u].find(v) == E[u].end()) {
            E[u].insert(v);
            ++in_deg[v];
        }
    }
    if (toposort()) {
        for (int i = 0; i < counter; ++i) {
            IO::writeln(answer[i]);
        }
    } else {
        puts("IMPOSSIBLE");
    }

    return 0;
}

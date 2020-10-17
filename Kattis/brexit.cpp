// https://open.kattis.com/problems/brexit
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using int128 = __int128;

constexpr int MAXN = 200005;

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

vector<vector<int> > adj;
vector<int> partners_leave;
bitset<MAXN> leave;
int c, p, x, l;

void bfs(int node) {
    leave[node] = true;
    queue<int> q;
    q.push(node);
    int u;
    while (!q.empty()) {
        if (leave[x]) return;
        u = q.front();
        q.pop();
        for (const auto &v : adj.at(u)) {
            ++partners_leave.at(v);
            if (partners_leave.at(v) * 2 >= (int)adj.at(v).size() && !leave[v]) {
                q.push(v);
                leave[v] = true;
            }
        }
    }
}


int main() {

    IO::read(c, p, x, l);
    adj.resize(c + 1);
    partners_leave.resize(c + 1);
    int u, v;
    for (int i = 0; i < p; ++i) {
        IO::read(u, v);
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    bfs(l);
    if (leave[x]) {
        puts("leave");
    } else {
        puts("stay");
    }

    return 0;
}

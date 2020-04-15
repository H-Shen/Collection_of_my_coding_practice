#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 100005;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <>
    inline
    void read(double &t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (c == '.') {
            double temp = 1.0;
            c = getchar_unlocked();
            while (isdigit(c)) {
                temp /= 10.0;
                t += temp * (c - 48);
                c = getchar_unlocked();
            }
        }
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

unordered_map<int, unordered_set<int> > G;
vector<int> A(MAXN);

void dfs(int start_node, int end_node) {
    // update the longest node number which can be reached
    A.at(start_node) = end_node;
    if (G.find(start_node) != G.end()) {
        for (const auto &adj_node : G[start_node]) {
            if (A.at(adj_node) == 0) {
                dfs(adj_node, end_node);
            }
        }
    }
}

int main() {

    int n, m, u, v;
    IO::read(n, m);
    while (m--) {
        IO::read(u, v);
        G[v].insert(u);
    }
    for (int start_node = n; start_node >= 1; --start_node) {
        if (A.at(start_node) == 0) {
            dfs(start_node, start_node);
        }
    }
    // output
    bool first_item = true;
    for (int i = 1; i <= n; ++i) {
        if (first_item) {
            first_item = false;
        } else {
            putchar_unlocked(' ');
        }
        IO::write(A.at(i));
    }
    putchar_unlocked('\n');
    return 0;
}
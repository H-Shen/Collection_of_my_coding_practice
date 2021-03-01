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

constexpr int INF = 0x3f3f3f3f;
constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int r, c, m, s_r, s_c, d_r, d_c, row, col, counter;
vector<vector<bool> > M;
vector<vector<int> > dist;

void bfs() {
    queue<pair<int, int> > q;
    q.push({s_r, s_c});
    dist.at(s_r).at(s_c) = 0;
    M.at(s_r).at(s_c) = true;
    int new_r, new_c;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        if (u.first == d_r && u.second == d_c) break;
        for (int step = 0; step < STEPS; ++step) {
            new_r = u.first + dx[step];
            new_c = u.second + dy[step];
            if (new_r >= 0 && new_r < r && new_c >= 0 && new_c < c && !M.at(new_r).at(new_c) && dist.at(new_r).at(new_c) == INF) {
                dist.at(new_r).at(new_c) = dist.at(u.first).at(u.second) + 1;
                q.push({new_r, new_c});
            }
        }
    }
}

int main() {

    while (true) {
        IO::read(r, c);
        if (r == 0 && c == 0) break;
        decltype(M)().swap(M);
        decltype(dist)().swap(dist);
        M.resize(r, vector<bool>(c, false));
        dist.resize(r, vector<int>(c, INF));
        IO::read(m);
        for (int i = 0; i < m; ++i) {
            IO::read(row, counter);
            for (int j = 0; j < counter; ++j) {
                IO::read(col);
                M.at(row).at(col) = true;
            }
        }
        IO::read(s_r, s_c, d_r, d_c);
        bfs();
        IO::writeln(dist.at(d_r).at(d_c));
    }
    return 0;
}
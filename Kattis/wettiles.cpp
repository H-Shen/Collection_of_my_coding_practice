// https://open.kattis.com/problems/wettiles
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using int128 = __int128;
using pii = pair<int, int>;

constexpr int MAXN = 1005;

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

constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int r, c, t, l, w;
vector<vector<int> > M; // -1: wall 0: unvisited 1: leak
vector<pii> leaks;

void bfs() {
    queue<pii> q;
    for (const auto &i : leaks) {
        q.push(i);
        M.at(i.first).at(i.second) = 1;
    }
    pii u;
    int new_i, new_j;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_i = u.first + dx[step];
            new_j = u.second + dy[step];
            if (new_i >= 1 && new_i <= r && new_j >= 1 && new_j <= c && M.at(new_i).at(new_j) != -1 && M.at(new_i).at(new_j) == 0) {
                q.push({new_i, new_j});
                if (M.at(u.first).at(u.second) == t) {
                    return;
                }
                M.at(new_i).at(new_j) = M.at(u.first).at(u.second) + 1;
            }
        }
    }
}

int main() {

    while (true) {
        IO::read(r);
        if (r == -1) break;
        IO::read(c, t, l, w);
        M.resize(r + 1, vector<int>(c + 1));
        leaks.resize(l);
        for (int i = 0; i < l; ++i) {
            IO::read(leaks.at(i).first, leaks.at(i).second);
        }
        if (w > 0) {
            int x1, y1, x2, y2;
            for (int i = 0; i < w; ++i) {
                IO::read(x1, y1, x2, y2);
                // along x-axis
                if (x1 == x2) {
                    if (y1 > y2) swap(y1, y2);
                    for (int y = y1; y <= y2; ++y) {
                        M.at(x1).at(y) = -1;
                    }
                }
                // along y-axis
                else if (y1 == y2) {
                    if (x1 > x2) swap(x1, x2);
                    for (int x = x1; x <= x2; ++x) {
                        M.at(x).at(y1) = -1;
                    }
                }
                // diagonal
                else {
                    if (x1 < x2 && y1 > y2) {
                        for (int x = x1, y = y1; x <= x2; ++x, --y) {
                            M.at(x).at(y) = -1;
                        }
                    }
                    else if (x1 > x2 && y1 < y2) {
                        for (int x = x1, y = y1; x >= x2; --x, ++y) {
                            M.at(x).at(y) = -1;
                        }
                    }
                    else if (x1 > x2 && y1 > y2) {
                        for (int x = x1, y = y1; x >= x2; --x, --y) {
                            M.at(x).at(y) = -1;
                        }
                    }
                    else if (x1 < x2 && y1 < y2) {
                        for (int x = x1, y = y1; x <= x2; ++x, ++y) {
                            M.at(x).at(y) = -1;
                        }
                    }
                }
            }
        }
        bfs();
        int counter = 0;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (M.at(i).at(j) != 0 && M.at(i).at(j) != -1) {
                    ++counter;
                }
            }
        }
        IO::writeln(counter);
        // reset
        decltype(leaks)().swap(leaks);
        decltype(M)().swap(M);
    }

    return 0;
}

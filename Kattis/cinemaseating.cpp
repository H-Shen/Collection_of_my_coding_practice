// https://open.kattis.com/problems/cinemaseating

#include <bits/extc++.h>

using namespace std;
using ll = long long;

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
        putchar('\n');
    }
}

constexpr int MAXN = 1005;
constexpr int N = 9;
constexpr int STEPS = 8;
const int dx[] = {-1,1,0,0,-1,1,-1,1};
const int dy[] = {0,0,-1,1,-1,1,1,-1};

bitset<MAXN> vis[MAXN];
int stats[N];
int r, c, n, r_val, c_val, new_i, new_j;

int main() {
    IO::read(r, c, n);
    while (n--) {
        IO::read(r_val, c_val);
        vis[r_val][c_val] = true;
    }
    int counter;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (vis[i][j]) {
                counter = 0;
                for (int step = 0; step < STEPS; ++step) {
                    new_i = i + dx[step];
                    new_j = j + dy[step];
                    if (new_i >= 1 && new_i <= r && new_j >= 1 && new_j <= c &&
                        vis[new_i][new_j]) {
                        ++counter;
                    }
                }
                ++stats[counter];
            }
        }
    }
    for (int stat : stats) {
        IO::write(stat);
        putchar_unlocked(' ');
    }
    return 0;
}

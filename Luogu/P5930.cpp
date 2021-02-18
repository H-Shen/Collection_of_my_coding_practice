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

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (x != father[x]) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

constexpr int STEPS = 4;
constexpr int MAX_HEIGHT = 10005;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int n, m;
vector<vector<int> > M;
vector<vector<pair<int, int> > > H(MAX_HEIGHT);

int main() {

    IO::read(n, m);
    int maxHeight = 0;
    M.resize(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            IO::read(M[i][j]);
            H[M[i][j]].emplace_back(i, j);
            maxHeight = max(maxHeight, M[i][j]);
        }
    }
    DSU::init(n * m);
    int new_i, new_j;
    int water_added_at_current_level = 0;
    int total_water_added = 0;
    for (int h = 0; h <= maxHeight; ++h) {
        for (const auto &[i, j] : H[h]) {
            ++water_added_at_current_level;
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                DSU::merge(i*m+j,n*m);
            }
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M[i][j] >= M[new_i][new_j]) {
                    DSU::merge(i * m + j, new_i * m + new_j);
                }
            }
        }
        // Remove all slots on the boundary at the current level
        // subtract 1 to remove m*n from DSU
        total_water_added += water_added_at_current_level - DSU::Size[DSU::find(m*n)] + 1;
    }
    IO::writeln(total_water_added);

    return 0;
}
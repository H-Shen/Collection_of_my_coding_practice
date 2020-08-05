#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
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
    vector<int> Size;
    vector<int> father;
    void init(int n) {
        vector<int>().swap(Size);
        vector<int>().swap(father);
        Size.resize(n + 5, 1);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

constexpr int MAXN = 35;
constexpr int STEPS = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

bitset<MAXN> vis[MAXN];
vector<vector<int> > M;
int n;

void dfs(int last_i, int last_j, int i, int j) {
    vis[i][j] = true;
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(last_i * n + last_j, i * n + j);
    }
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && !vis[new_i][new_j] && M.at(new_i).at(new_j) == 0) {
            dfs(i, j, new_i, new_j);
        }
    }
}

int main() {

    IO::read(n);
    M.resize(n, vector<int>(n));
    for (auto &i : M) {
        for (auto &j : i) {
            IO::read(j);
        }
    }
    DSU::init(n * n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M.at(i).at(j) == 0 && !vis[i][j]) {
                dfs(-1, -1, i, j);
            }
        }
    }
    unordered_map<int, vector<int>, custom_hash> groups;
    unordered_set<int, custom_hash> components_touch_boundaries;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (M.at(i).at(j) == 0) {
                groups[DSU::find(i * n + j)].emplace_back(i * n + j);
            }
        }
    }
    int pos_i, pos_j;
    bool touch;
    for (const auto &[k, v_] : groups) {
        touch = false;
        for (const auto &pos : v_) {
            pos_i = pos / n;
            pos_j = pos % n;
            if (pos_i == 0 || pos_i == n - 1 || pos_j == 0 || pos_j == n - 1) {
                touch = true;
                break;
            }
        }
        if (touch) {
            components_touch_boundaries.insert(k);
        }
    }
    // color with '2'
    for (const auto &[k, v_] : groups) {
        if (components_touch_boundaries.find(k) == components_touch_boundaries.end()) {
            for (const auto &pos : v_) {
                pos_i = pos / n;
                pos_j = pos % n;
                M.at(pos_i).at(pos_j) = 2;
            }
        }
    }
    // output
    for (int i = 0; i < n; ++i) {
        IO::write(M.at(i).at(0));
        for (int j = 1; j < n; ++j) {
            putchar_unlocked(' ');
            IO::write(M.at(i).at(j));
        }
        putchar_unlocked('\n');
    }

    return 0;
}
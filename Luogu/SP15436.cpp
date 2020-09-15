#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

constexpr int MAXN = 255;
constexpr int STEPS = 4;
constexpr array<int, STEPS> dx = {0, 0, 1, -1};
constexpr array<int, STEPS> dy = {1, -1, 0, 0};

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
        putchar('\n');
    }
}


namespace DSU {
    vector<int> father;
    vector<int> Size;

    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
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
        if (x == y) return;
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
}

int n, m;
vector<vector<int> > M;
bitset<MAXN> vis[MAXN];

void dfs(int last_i, int last_j, int cur_i, int cur_j) {
    if (!(last_i == -1 && last_j == -1)) {
        DSU::merge(last_i * m + last_j, cur_i * m + cur_j);
    }
    if (vis[cur_i][cur_j]) {
        return;
    }
    vis[cur_i][cur_j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = cur_i + dx[step];
        new_j = cur_j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
            M.at(new_i).at(new_j) == 1) {
            dfs(cur_i, cur_j, new_i, new_j);
        }
    }
}

int main() {

    while (true) {
        IO::read(n, m);
        if (n == 0 && m == 0) break;
        M.resize(n, vector<int>(m));
        DSU::init(n * m);
        for (auto &i : M) {
            for (auto &j : i) {
                IO::read(j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M.at(i).at(j) == 1 && !vis[i][j]) {
                    dfs(-1, -1, i, j);
                }
            }
        }
        unordered_map<int, int, custom_hash> groupid_2_size;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (M.at(i).at(j) == 1) {
                    ++groupid_2_size[DSU::find(i * m + j)];
                }
            }
        }
        unordered_map<int, int, custom_hash> size_2_freq;
        for (const auto &i : groupid_2_size) {
            ++size_2_freq[i.second];
        }
        vector<pii> output(size_2_freq.begin(), size_2_freq.end());
        sort(output.begin(), output.end(), [](const pii &l, const pii &r) {
            return l.first < r.first;
        });
        // output
        IO::writeln(groupid_2_size.size());
        for (const auto &i : output) {
            IO::write(i.first);
            putchar(' ');
            IO::writeln(i.second);
        }
        // clear
        decltype(M)().swap(M);
        for (auto &i : vis) {
            i.reset();
        }
    }

    return 0;
}

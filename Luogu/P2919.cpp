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

    template<typename T, typename... Args>
    inline void writeln(T t, Args... args) {
        writeln(t);
        writeln(args...);
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
        if (x != father[x]) {
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
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
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

constexpr int MAXN = 705;
constexpr int STEPS = 8;
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
const int dy[] = {0, 0, -1, 1, 1, 1, -1, -1};

int n, m;
vector<vector<int> > M;
bitset<MAXN> vis[MAXN];
unordered_map<int, vector<int>, custom_hash> group_id_2_elements;

void dfs(int i, int j) {
    vis[i][j] = true;
    int new_i, new_j;
    for (int step = 0; step < STEPS; ++step) {
        new_i = i + dx[step];
        new_j = j + dy[step];
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && M.at(i).at(j) == M.at(new_i).at(new_j) && !vis[new_i][new_j]) {
            DSU::merge(i * m + j, new_i * m + new_j);
            dfs(new_i, new_j);
        }
    }
}

int main() {

    IO::read(n, m);
    M.resize(n, vector<int>(m));
    for (auto &i : M) {
        for (auto &j : i) {
            IO::read(j);
        }
    }
    DSU::init(n * m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                dfs(i, j);
            }
        }
    }
    for (int i = 0; i < n * m; ++i) {
        group_id_2_elements[DSU::find(i)].emplace_back(i);
    }
    int cur_pos_i, cur_pos_j, new_pos_i, new_pos_j;
    int counter = 0;
    bool have_ans;
    for (const auto &[k, v] : group_id_2_elements) {
        have_ans = true;
        // Check all adjacent cells of this component
        for (const auto v_ : v) {
            cur_pos_i = v_ / m;
            cur_pos_j = v_ % m;
            // check 8 directions
            for (int step = 0; step < STEPS; ++step) {
                new_pos_i = cur_pos_i + dx[step];
                new_pos_j = cur_pos_j + dy[step];
                if (new_pos_i >= 0 && new_pos_i < n && new_pos_j >= 0 && new_pos_j < m && M.at(new_pos_i).at(new_pos_j) > M.at(cur_pos_i).at(cur_pos_j)) {
                    have_ans = false;
                    break;
                }
            }
            if (!have_ans) {
                break;
            }
        }
        if (have_ans) {
            ++counter;
        }
    }
    IO::writeln(counter);

    return 0;
}
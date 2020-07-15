// https://open.kattis.com/problems/ballsandneedles
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1005;

// DSU for 3d points
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

// DSU for 2d points
namespace DSU_copy {
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

    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

int n;
unordered_map<int, int, custom_hash> points_2d, points_3d;
int id_of_3d_points, id_of_2d_points;

// reversed edges or duplicated edges or an edge from any two same points are ignored
unordered_set<pair<int, int>, custom_hash> unique_edges_of_3d_points, unique_edges_of_2d_points;

int main(int argc, char *argv[]) {

    IO::read(n);
    int x1, y1, z1, x2, y2, z2, u, v;
    unordered_map<int, int, custom_hash>::const_iterator iter;
    bool has_true_closed_chains = false;
    bool has_floor_closed_chains = false;

    for (int i = 0; i < n; ++i) {
        IO::read(x1, y1, z1, x2, y2, z2);

        // process 3d points
        iter = points_3d.find(x1 * MAXN * MAXN + y1 * MAXN + z1);
        if (iter == points_3d.end()) {
            points_3d[x1 * MAXN * MAXN + y1 * MAXN + z1] = id_of_3d_points;
            u = id_of_3d_points;
            ++id_of_3d_points;
        } else {
            u = iter->second;
        }
        iter = points_3d.find(x2 * MAXN * MAXN + y2 * MAXN + z2);
        if (iter == points_3d.end()) {
            points_3d[x2 * MAXN * MAXN + y2 * MAXN + z2] = id_of_3d_points;
            v = id_of_3d_points;
            ++id_of_3d_points;
        } else {
            v = iter->second;
        }
        if (u != v) {
            if (u > v) {
                swap(u, v);
            }
            unique_edges_of_3d_points.insert(make_pair(u, v));
        }

        // process 2d points
        iter = points_2d.find(x1 * MAXN + y1);
        if (iter == points_2d.end()) {
            points_2d[x1 * MAXN + y1] = id_of_2d_points;
            u = id_of_2d_points;
            ++id_of_2d_points;
        } else {
            u = iter->second;
        }
        iter = points_2d.find(x2 * MAXN + y2);
        if (iter == points_2d.end()) {
            points_2d[x2 * MAXN + y2] = id_of_2d_points;
            v = id_of_2d_points;
            ++id_of_2d_points;
        } else {
            v = iter->second;
        }
        if (u != v) {
            if (u > v) {
                swap(u, v);
            }
            unique_edges_of_2d_points.insert(make_pair(u, v));
        }
    }
    // process 3d points
    DSU::init(id_of_3d_points);
    for (const auto &[i, j] : unique_edges_of_3d_points) {
        if (DSU::is_same_group(i, j)) {
            has_true_closed_chains = true;
            break;
        }
        DSU::merge(i, j);
    }

    // process 2d points
    DSU_copy::init(id_of_2d_points);
    for (const auto &[i, j] : unique_edges_of_2d_points) {
        if (DSU_copy::is_same_group(i, j)) {
            has_floor_closed_chains = true;
            break;
        }
        DSU_copy::merge(i, j);
    }

    // output
    if (has_true_closed_chains) {
        fputs_unlocked("True closed chains\n", stdout);
    } else {
        fputs_unlocked("No true closed chains\n", stdout);
    }
    if (has_floor_closed_chains) {
        fputs_unlocked("Floor closed chains\n", stdout);
    } else {
        fputs_unlocked("No floor closed chains\n", stdout);
    }

    return 0;
}

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

int main() {

    int t, n, id, i, j, e;
    bool yes;
    IO::read(t);
    while (t--) {
        yes = true;
        IO::read(n);
        gp_hash_table<int, int, custom_hash> val2id;
        id = 0;
        vector<pair<int, int> > inequality_restrictions;
        vector<pair<int, int> > equality_restrictions;
        while (n--) {
            IO::read(i, j, e);
            if (val2id.find(i) == val2id.end()) {
                val2id[i] = id;
                ++id;
            }
            if (val2id.find(j) == val2id.end()) {
                val2id[j] = id;
                ++id;
            }
            if (e == 1) {
                equality_restrictions.emplace_back(make_pair(val2id[i], val2id[j]));
            } else {
                inequality_restrictions.emplace_back(make_pair(val2id[i], val2id[j]));
            }
        }
        DSU::init(id + 5);
        for (const auto &[l, r] : equality_restrictions) {
            DSU::merge(l, r);
        }
        for (const auto &[l, r] : inequality_restrictions) {
            if (DSU::is_same_group(l, r)) {
                yes = false;
                break;
            }
        }
        if (yes) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
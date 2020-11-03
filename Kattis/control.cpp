// https://open.kattis.com/problems/control
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 500005;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        father.resize(n + 5);
        Size.resize(n + 5, 1);
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
        if (x == y) return;
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

namespace IO {
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

    DSU::init(MAXN);
    int n, m;
    int counter = 0;
    bool have_ans;
    IO::read(n);
    while (n--) {
        IO::read(m);
        unordered_map<int, int, custom_hash> unmap;
        vector<int> A(m);
        for (auto &i : A) {
            IO::read(i);
            ++unmap[DSU::find(i)];
        }
        have_ans = true;
        for (const auto &[k, v] : unmap) {
            if (DSU::Size[k] != v) {
                have_ans = false;
                break;
            }
        }
        if (have_ans) {
            ++counter;
            if (m > 1) {
                for (int i = 0; i < m - 1; ++i) {
                    DSU::merge(A.at(i), A.at(i + 1));
                }
            }
        }
    }
    IO::writeln(counter);
    return 0;
}

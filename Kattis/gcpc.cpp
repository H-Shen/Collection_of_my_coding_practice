// https://open.kattis.com/problems/gcpc
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

struct Team {
    int number;
    int a;
    int b;
    bool operator < (const Team &other) const {
        if (a == other.a) {
            if (b == other.b) {
                return number < other.number;
            }
            return b < other.b;
        }
        return a > other.a;
    }
    explicit Team(int number, int a, int b) : number(number), a(a), b(b) {}
    Team() = default;
};

using RBTree = tree<Team, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

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
gp_hash_table<int, Team, custom_hash> unmap;
RBTree Tree;

int main() {

    int n, m, t, p;
    IO::read(n, m);
    for (int i = 1; i <= n; ++i) {
        Team temp(i, 0, 0);
        unmap[i] = temp;
        Tree.insert(temp);
    }
    while (m--) {
        IO::read(t, p);
        Tree.erase(unmap[t]);
        ++unmap[t].a;
        unmap[t].b += p;
        Tree.insert(unmap[t]);
        IO::writeln(Tree.order_of_key(unmap[1]) + 1);
    }
    return 0;
}
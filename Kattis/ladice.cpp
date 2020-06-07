// https://open.kattis.com/problems/ladice
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    vector<int> used;
    void init(int n) {
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        used.resize(n + 5, 0);
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
        used[y] += used[x];
    }
    bool has_incremented(int x) {
        x = find(x);
        ++used[x];
        if (used[x] > Size[x]) {
            --used[x];
            return false;
        }
        return true;
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

int main() {

    int n, l, a, b;
    IO::read(n, l);
    DSU::init(l);
    while (n--) {
        IO::read(a, b);
        DSU::merge(a, b);
        if (DSU::has_incremented(a)) {
            fputs_unlocked("LADICA\n", stdout);
        } else {
            fputs_unlocked("SMECE\n", stdout);
        }
    }

    return 0;
}

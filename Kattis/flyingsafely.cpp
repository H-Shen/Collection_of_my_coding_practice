// https://open.kattis.com/problems/flyingsafely
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
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

namespace DSU {
    vector<int> father;
    vector<int> Size;
    inline
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    inline
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    inline
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

int main() {

    int t, n, m;
    IO::read(t);
    while (t--) {
        IO::read(n, m);
        DSU::init(n);
        vector<pair<int, int> > A(m);
        for (auto &i : A) {
            IO::read(i.first, i.second);
        }
        int result = 0;
        for (const auto &[u, v] : A) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                ++result;
            }
        }
        IO::writeln(result);
    }
    return 0;
}

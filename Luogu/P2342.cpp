#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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
    template<>
    inline
    void read(char &t) {
        t = getchar_unlocked();
        while (!isalpha(t)) {
            t = getchar_unlocked();
        }
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

namespace DSU {
    vector<int> father;
    vector<int> Weight;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Weight);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Weight.resize(n + 5, 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (father[x] != x) {
            int temp = find(father[x]);
            Weight[x] += Weight[father[x]];
            father[x] = temp;
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        father[x] = y;
        Weight[x] = Size[y];
        Size[y] += Size[x];
    }
}

constexpr int MAXN = 30000;

int main() {

    int p;
    char op;
    int x, y, z;
    IO::read(p);
    DSU::init(MAXN);
    while (p--) {
        IO::read(op);
        if (op == 'M') {
            IO::read(x, y);
            DSU::merge(x, y);
        } else {
            IO::read(z);
            DSU::find(z);
            IO::writeln(DSU::Weight[z]);
        }
    }

    return 0;
}
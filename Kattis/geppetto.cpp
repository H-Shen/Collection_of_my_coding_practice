// https://open.kattis.com/problems/geppetto

#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

constexpr int MAXN = 21;
int n,m,u,v;
vector<pair<int,int>> restrict;

int main() {
    IO::read(n,m);
    unordered_map<int,unordered_set<int>> unmap;
    for (int i = 0; i < m; ++i) {
        IO::read(u,v);
        if (u > v) swap(u,v);
        unmap[u].insert(v);
    }
    for (auto &[i,j] : unmap) {
        for (auto &k : j) {
            restrict.emplace_back(i-1,k-1);
        }
    }
    int total = (1<<n)-1;
    bool hasAns;
    int counter = 0;
    for (int i = 0; i <= total; ++i) {
        bitset<MAXN> bs(i);
        hasAns = true;
        for (auto &[j,k] : restrict) {
            if (bs[j] && bs[k]) {
                hasAns = false;
                break;
            }
        }
        if (hasAns) {
            ++counter;
        }
    }
    IO::writeln(counter);
    return 0;
}

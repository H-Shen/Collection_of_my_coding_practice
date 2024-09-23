// https://www.nowcoder.com/practice/0ba5d8f525494a8787aaa9d53b5f9b9e

#include <bits/stdc++.h>

using namespace std;

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
}

vector<int> degrees;

int main() {
    int n, m, u, v;
    while (~scanf("%d", &n) && n != 0) {
        vector<int>().swap(degrees);
        degrees.resize(n + 5);
        DSU::init(n);
        IO::read(m);
        while (m--) {
            IO::read(u, v);
            if (u != v) {
                ++degrees.at(u);
                ++degrees.at(v);
                DSU::merge(u, v);
            }
        }
        unordered_map<int, unordered_set<int> > groups;
        for (int i = 1; i <= n; ++i) {
            groups[DSU::find(i)].insert(i);
        }
        bool hasEulerCircuit = false;
        for (const auto &i : groups) {
            if (i.second.size() <= 1) {
                continue;
            }
            hasEulerCircuit = true;
            for (const auto &node : i.second) {
                if (degrees.at(node) & 1) {
                    hasEulerCircuit = false;
                    break;
                }
            }
            if (hasEulerCircuit) {
                IO::writeln(1);
                break;
            }
        }
        if (!hasEulerCircuit) {
            IO::writeln(0);
        }
    }
    return 0;
}

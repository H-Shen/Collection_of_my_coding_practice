// https://open.kattis.com/problems/magicallights
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 300005;
constexpr int NODE_UPPERBOUND = 100;

vector<int> Color;
vector<vector<int> > adj;
vector<int> dfs_start;
vector<int> dfs_end;
int counter;
int n, q, u, v;

namespace BIT {
    int t[MAXN][150];
    int lowbit(int x) {
        return x & (-x);
    }
    void update(int l, int r, int new_value) {
        for (int i = l; i <= n; i += lowbit(i)) {
            t[i][r] += new_value;
        }
    }
    int get_sum(int l, int r) {
        int sum = 0;
        for (int i = l; i >= 1; i -= lowbit(i)) {
            sum += t[i][r];
        }
        return sum;
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

void dfs(int u) {
    dfs_start.at(u) = ++counter;
    for (auto &v : adj.at(u)) {
        dfs(v);
    }
    dfs_end.at(u) = counter;
}

int main() {

    IO::read(n, q);
    Color.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
        IO::read(Color.at(i));
    }
    adj.resize(n + 5);
    for (int i = 1; i < n; ++i) {
        IO::read(u);
        v = i + 1;
        adj.at(u).emplace_back(v);
    }
    dfs_start.resize(n + 5);
    dfs_end.resize(n + 5);
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        BIT::update(dfs_start.at(i), Color.at(i), 1);
    }
    int x, k, result, temp;

    while (q--) {
        IO::read(k, x);
        if (k == 0) {
            result = 0;
            for (int i = 1; i <= NODE_UPPERBOUND; ++i) {
                temp = BIT::get_sum(dfs_end.at(x), i) - BIT::get_sum(dfs_start.at(x) - 1, i);
                if (temp % 2 == 1) {
                    ++result;
                }
            }
            IO::writeln(result);
        } else {
            BIT::update(dfs_start.at(x), Color.at(x), -1);
            BIT::update(dfs_start.at(x), k, 1);
            Color.at(x) = k;
        }
    }

    return 0;
}

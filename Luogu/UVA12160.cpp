#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

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

constexpr int MOD = 10000;
constexpr int INF = 0x3f3f3f3f;

int l, u, r;
vector<int> steps;
array<int, MOD + 5> dis;
void bfs() {
    queue<int> q;
    q.push(l);
    dis.at(l) = 0;
    int cur_i, new_i;
    while (!q.empty()) {
        cur_i = q.front();
        q.pop();
        for (const auto &i : steps) {
            new_i = (cur_i + i) % MOD;
            if (dis.at(new_i) > dis.at(cur_i) + 1) {
                dis.at(new_i) = dis.at(cur_i) + 1;
                q.push(new_i);
            }
        }
    }
}

int main() {

    int kase = 1;
    while (true) {
        IO::read(l, u, r);
        if (l == 0 && u == 0 && r == 0) break;
        fill(dis.begin(), dis.end(), INF);
        vector<int>().swap(steps);
        steps.resize(r);
        for (auto &i : steps) {
            IO::read(i);
        }
        bfs();
        printf("Case %d: ", kase++);
        if (dis.at(u) == INF) {
            puts("Permanently Locked");
        } else {
            IO::writeln(dis.at(u));
        }
    }

    return 0;
}
// https://open.kattis.com/problems/horror
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int INF = 0x3f3f3f3f;

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

vector<int> dis;
vector<vector<int> > adj;
void bfs(int node) {
    queue<int> q;
    q.push(node);
    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        for (const auto &v : adj.at(u)) {
            if (dis.at(v) > dis.at(u) + 1) {
                dis.at(v) = dis.at(u) + 1;
                q.push(v);
            }
        }
    }
}

int main() {

    int n, h, l, u, v;
    IO::read(n, h, l);
    dis.resize(n + 5, INF);
    adj.resize(n + 5);

    vector<int> horror_films(h);
    for (auto &i : horror_films) {
        IO::read(i);
        dis.at(i) = 0;
    }
    while (l--) {
        IO::read(u, v);
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    for (const auto &i : horror_films) {
        bfs(i);
    }
    int highest_horror_index = -1;
    int answer_id = INF;
    for (int i = 0; i < n; ++i) {
        if (dis.at(i) > highest_horror_index) {
            highest_horror_index = dis.at(i);
            answer_id = i;
        } else if (dis.at(i) == highest_horror_index) {
            answer_id = min(answer_id, i);
        }
    }
    IO::writeln(answer_id);

    return 0;
}

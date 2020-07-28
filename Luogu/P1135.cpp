#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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

constexpr int INF = 0x3f3f3f3f;

int n, a, b;
vector<int> steps;
vector<int> dis;

void bfs() {
    queue<int> q;
    q.push(a);
    dis.at(a) = 0;
    while (!q.empty()) {
        int current_pos = q.front();
        q.pop();
        // Check 2 directions
        int new_pos;
        new_pos = current_pos + steps.at(current_pos);
        if (new_pos >= 1 && new_pos <= n && dis.at(new_pos) == INF) {
            q.push(new_pos);
            dis.at(new_pos) = dis.at(current_pos) + 1;
        }
        new_pos = current_pos - steps.at(current_pos);
        if (new_pos >= 1 && new_pos <= n && dis.at(new_pos) == INF) {
            q.push(new_pos);
            dis.at(new_pos) = dis.at(current_pos) + 1;
        }
    }
}

int main() {

    IO::read(n, a, b);
    steps.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        IO::read(steps.at(i));
    }
    dis.resize(n + 5, INF);
    bfs();
    if (dis.at(b) == INF) {
        IO::writeln(-1);
    } else {
        IO::writeln(dis.at(b));
    }

    return 0;
}
// https://open.kattis.com/problems/millionairemadness
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
using int128 = __int128;
using pii = pair<int, int>;

constexpr int MAXN = 1005;
constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

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

struct Node {
    int x, y;
    ll gap;
    explicit Node(int x, int y, ll gap) : x(x), y(y), gap(gap) {}
    bool operator > (const Node &other) const {
        return gap > other.gap;
    }
};

int n, m, dest_i, dest_j;
vector<vector<int> > M;
bitset<MAXN> vis[MAXN];

ll bfs(Node u) {
    __gnu_pbds::priority_queue<Node, greater<>, __gnu_pbds::pairing_heap_tag> pq;
    pq.push(u);
    ll maximal_length = -1;
    int new_x, new_y;
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();
        if (vis[u.x][u.y]) {
            continue;
        }
        vis[u.x][u.y] = true;
        maximal_length = max(maximal_length, u.gap);
        if (u.x == dest_i && u.y == dest_j) {
            break;
        }
        for (int step = 0; step < STEPS; ++step) {
            new_x = u.x + dx[step];
            new_y = u.y + dy[step];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                if (M.at(new_x).at(new_y) > M.at(u.x).at(u.y)) {
                    pq.push(Node(new_x, new_y, M.at(new_x).at(new_y) - M.at(u.x).at(u.y)));
                } else {
                    pq.push(Node(new_x, new_y, 0));
                }
            }
        }
    }
    return maximal_length;
}

int main() {

    IO::read(n, m);
    M.resize(n, vector<int>(m));
    for (auto &i : M) {
        for (auto &j : i) {
            IO::read(j);
        }
    }
    dest_i = n - 1;
    dest_j = m - 1;
    IO::writeln(bfs(Node(0, 0, 0)));
    return 0;
}

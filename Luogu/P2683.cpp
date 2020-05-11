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

namespace SSSP {
    constexpr int MAX_NODES = 105;
    constexpr int MAX_EDGES = 10005;
    constexpr ll INF = 0x3f3f3f3f3f;
    struct Edge {
        int to;
        ll distance;
        int next;
        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };
    vector<Edge> E(MAX_EDGES);
    vector<int> head(MAX_NODES);
    int counter;
    vector<ll> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    int s;

    inline void
    add_edge(int u, int v, ll d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }
    struct Node {
        ll distance;
        int position;

        explicit Node(ll distance, int pos) : distance(distance), position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };
    std::priority_queue<Node> Q;
    inline void dijkstra() {
        dis.at(s) = 0;
        Q.push(Node(0, s));
        while (!Q.empty()) {
            Node tmp = Q.top();
            Q.pop();
            int x = tmp.position;
            // Base case
            if (vis.at(x)) {
                continue;
            }
            vis.at(x) = true;
            for (int i = head.at(x); i; i = E.at(i).next) {
                int y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (!vis.at(y)) {
                        Q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
    inline void reset() {
        fill(dis.begin(), dis.end(), INF);
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        Q = std::priority_queue<Node>();
    }
}

int main() {

    int n, m, op, s, t, u, v;
    ll e, answer;
    IO::read(n, m);
    while (m--) {
        IO::read(op);
        if (op == 0) {
            IO::read(s, t);
            SSSP::reset();
            SSSP::s = s;
            SSSP::dijkstra();
            answer = SSSP::dis.at(t);
            if (answer == SSSP::INF) {
                IO::writeln(-1);
            } else {
                IO::writeln(answer);
            }
        } else {
            IO::read(u, v, e);
            SSSP::add_edge(u, v, e);
            SSSP::add_edge(v, u, e);
        }
    }

    return 0;
}

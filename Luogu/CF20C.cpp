#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

namespace SSSP {
    constexpr int MAX_NODES = 100050;
    constexpr int MAX_EDGES = 200050;
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
    vector<int> prev(MAX_NODES, -1);
    int counter;
    vector<ll> dis(MAX_NODES);
    bitset<MAX_NODES> vis;
    int s;

    inline void add_edge(int u, int v, ll d) {
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
    std::priority_queue<Node> q;
    inline void dijkstra(bool store_path = false) {
        dis.at(s) = 0;
        q.push(Node(0, s));
        while (!q.empty()) {
            Node tmp = q.top();
            q.pop();
            int x = tmp.position;
            // Base case
            if (vis[x]) {
                continue;
            }
            vis[x] = true;
            for (int i = head.at(x); i; i = E.at(i).next) {
                int y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (store_path) {
                        prev.at(y) = x;
                    }
                    if (!vis[y]) {
                        q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
    inline void reset() {
        fill(dis.begin(), dis.end(), INF);
        vis.reset();
        q = std::priority_queue<Node>();
    }
    vector<int> get_path(int t) {
        vector<int> path;
        for(; t!=-1; t=prev.at(t))
            path.push_back(t);
        reverse(path.begin(),path.end());
        return path;
    }
}

int main() {

    int n, m, u, v;
    ll w;
    IO::read(n, m);
    SSSP::reset();
    while (m--) {
        IO::read(u, v, w);
        SSSP::add_edge(u, v, w);
        SSSP::add_edge(v, u, w);
    }
    SSSP::s = 1;
    SSSP::dijkstra(true);
    if (SSSP::dis.at(n) == SSSP::INF) {
        IO::writeln(-1);
    } else {
        auto path = SSSP::get_path(n);
        bool firstItem = true;
        for (const auto &i : path) {
            if (firstItem) {
                firstItem = false;
            } else {
                putchar(' ');
            }
            IO::write(i);
        }
        putchar(' ');
    }

    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int N = 20;

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

namespace SSSP {

    constexpr int MAX_NODES = 505;
    constexpr int MAX_EDGES = 255025;
    constexpr int INF = 0x3f3f3f3f;

    struct Edge {
        int to;
        int distance;
        int next;

        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };

    vector<Edge> E(MAX_EDGES);
    vector<int> head(MAX_NODES);
    int counter;
    vector<int> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    int s;

    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }

    struct Node {
        int distance;
        int position;

        explicit Node(int distance, int pos) : distance(distance),
                                               position(pos) {}

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
        // reset dis
        fill(dis.begin(), dis.end(), INF);
        // reset vis
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        // reset Q
        Q = std::priority_queue<Node>();
        // reset counter
        counter = 0;
        // reset s
        s = 0;
        // reset E
        vector<Edge>().swap(E);
        E.resize(MAX_EDGES);
        // reset head
        vector<int>().swap(head);
        head.resize(MAX_NODES);
    }
}

vector<pair<int, int> > transitions = {
        {1,  -2},
        {1,  2},
        {-2, 1},
        {-2, -1},
        {-1, 2},
        {-1, -2},
        {2,  -1},
        {2,  1},
        {2,  2},
        {2,  -2},
        {-2, -2},
        {-2, 2}
};

vector<vector<bool> > vis;
unordered_map<int, unordered_set<int> > adj;
int original_i_0, original_j_0, original_i_1, original_j_1;
int dest_i = 1;
int dest_j = 1;

void dfs(int last, int i, int j) {
    int pos = i * N + j;
    if (last != -1) {
        adj[last].insert(pos);
    }
    if (vis.at(i).at(j)) {
        return;
    }
    vis.at(i).at(j) = true;
    if (i == dest_i && j == dest_j) {
        return;
    }
    int new_i, new_j;
    for (const auto &step : transitions) {
        new_i = i + step.first;
        new_j = j + step.second;
        if (new_i >= 1 && new_i <= N && new_j >= 1 && new_j <= N) {
            dfs(pos, new_i, new_j);
        }
    }
}

void reset() {
    // reset vis
    vector<vector<bool> >().swap(vis);
    vis.resize(N + 1, vector<bool>(N + 1, false));
    // reset adj
    adj.clear();
}

int main() {

    IO::read(original_i_0, original_j_0, original_i_1, original_j_1);

    // Calculate the shortest path for the first position
    reset();
    SSSP::reset();
    dfs(-1, original_i_0, original_j_0);
    // add edges
    for (const auto &[u, v_list] : adj) {
        for (const auto &v : v_list) {
            SSSP::add_edge(u, v, 1);
        }
    }
    SSSP::s = original_i_0 * N + original_j_0;
    SSSP::dijkstra();
    IO::writeln(SSSP::dis.at(dest_i * N + dest_j));

    // Calculate the shortest path for the second position
    // Case 1: Same position, no need to re-calculate
    if (original_i_0 == original_i_1 && original_j_0 == original_j_1) {
        IO::writeln(SSSP::dis.at(dest_i * N + dest_j));
    }
    // Case 2: Different position
    else {
        reset();
        SSSP::reset();
        dfs(-1, original_i_1, original_j_1);
        // add edges
        for (const auto &[u, v_list] : adj) {
            for (const auto &v : v_list) {
                SSSP::add_edge(u, v, 1);
            }
        }
        SSSP::s = original_i_1 * N + original_j_1;
        SSSP::dijkstra();
        IO::writeln(SSSP::dis.at(dest_i * N + dest_j));
    }
    return 0;
}
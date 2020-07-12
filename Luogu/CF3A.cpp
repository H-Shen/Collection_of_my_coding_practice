#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 8;
inline const vector<pair<int, int> > steps = {
        {0,  -1},
        {0,  1},
        {-1, 0},
        {1,  0},
        {-1, -1},
        {-1, 1},
        {1,  -1},
        {1,  1}
};

namespace SSSP {

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

    struct Node {
        int distance;
        int position;

        explicit Node(int distance, int pos) : distance(distance),
                                               position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };

    vector<Edge> E;
    vector<int> head;
    int counter;
    vector<int> dis;
    vector<bool> vis;
    std::priority_queue<Node> q;
    int source;
    vector<int> prev;

    void init(int number_of_nodes, int number_of_edges) {
        E.resize(number_of_edges + 5);
        head.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        vis.resize(number_of_nodes + 5);
        prev.resize(number_of_nodes, -1);
    }

    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }

    inline void dijkstra(bool store_path = false) {
        dis.at(source) = 0;
        q.push(Node(0, source));
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

    vector<int> get_path(int t) {
        vector<int> path;
        for (; t != -1; t = prev.at(t))
            path.push_back(t);
        reverse(path.begin(), path.end());
        return path;
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline
pair<int, int> convert(const string &s) {
    return make_pair(MAXN - s.back() + '0', s.front() - 'a');
}

inline
pair<int, int> convert(const int &pos) {
    return make_pair(pos / MAXN, pos % MAXN);
}

bitset<MAXN> vis[MAXN];
unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;
int origin_i, origin_j, dest_i, dest_j;

inline
void dfs(int last, int i, int j) {
    int pos = i * MAXN + j;
    if (last != -1) {
        G[last].insert(pos);
    }
    if (vis[i][j]) {
        return;
    }
    vis[i][j] = true;
    if (i == dest_i && j == dest_j) {
        return;
    }
    // iterate 8 directions
    int new_i;
    int new_j;
    for (const auto &[x, y] : steps) {
        new_i = i + x;
        new_j = j + y;
        if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN) {
            dfs(i * MAXN + j, new_i, new_j);
        }
    }
}

inline
string get_direction(const pair<int, int> &last_pos,
                     const pair<int, int> &current_pos) {
    string result;
    int di = current_pos.first - last_pos.first;
    int dj = current_pos.second - last_pos.second;
    if (di == 0) {
        if (dj == 1) {
            result = "R";
        } else {
            result = "L";
        }
    } else if (di == -1) {
        if (dj == 0) {
            result = "U";
        } else if (dj == 1) {
            result = "RU";
        } else {
            result = "LU";
        }
    } else {
        if (dj == 0) {
            result = "D";
        } else if (dj == 1) {
            result = "RD";
        } else {
            result = "LD";
        }
    }
    return result;
}

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    auto p = convert(s);
    origin_i = p.first;
    origin_j = p.second;
    cin >> s;
    p = convert(s);
    dest_i = p.first;
    dest_j = p.second;
    dfs(-1, origin_i, origin_j);

    int total_edges = 0;
    for (const auto &[k, v_list] : G) {
        total_edges += static_cast<int>(v_list.size());
    }
    SSSP::init(MAXN * MAXN, total_edges);
    for (const auto &[k, v_list] : G) {
        for (const auto &v : v_list) {
            SSSP::add_edge(k, v, 1);
        }
    }
    SSSP::source = origin_i * MAXN + origin_j;
    SSSP::dijkstra(true);

    // output
    cout << SSSP::dis.at(dest_i * MAXN + dest_j) << '\n';
    vector<int> path = SSSP::get_path(dest_i * MAXN + dest_j);
    int length = static_cast<int>(path.size());
    for (int i = 1; i < length; ++i) {
        cout << get_direction(convert(path.at(i - 1)), convert(path.at(i)))
             << '\n';
    }

    return 0;
}
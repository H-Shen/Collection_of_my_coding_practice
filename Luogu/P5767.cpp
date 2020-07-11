#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

const regex r("[0-9]+");

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

    void init(int number_of_nodes, int number_of_edges) {
        E.resize(number_of_edges + 10);
        head.resize(number_of_nodes + 10);
        dis.resize(number_of_nodes + 10, INF);
        vis.resize(number_of_nodes + 10);
    }

    int s;

    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }

    inline void dijkstra() {
        dis.at(s) = 0;
        q.push(Node(0, s));
        while (!q.empty()) {
            Node tmp = q.top();
            q.pop();
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
                        q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
}

inline static
vector<int> split_by_spaces(const string &s) {
    vector<int> res;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
         it != end_it; ++it) {
        res.emplace_back(stoi(it->str()));
    }
    return res;
}

struct Edge {
    int u, v, w;
    explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

int m, n;
vector<vector<int> > list_of_stations;
vector<Edge> edges;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    vector<int> p;
    getline(cin, s);
    p = split_by_spaces(s);
    // Case 1: m and n are on the same line
    if (p.size() == 1) {
        m = p.front();
        getline(cin, s);
        p = split_by_spaces(s);
        n = p.front();
    }
    // Case 2: m and n are on two separated lines
    else {
        m = p.front();
        n = p.back();
    }
    for (int i = 0; i < m; ++i) {
        getline(cin, s);
        p = split_by_spaces(s);
        if (p.size() > 1) {
            list_of_stations.emplace_back(p);
        }
    }
    // Obtain all intersected list_of_stations by calculating its freq
    unordered_map<int, vector<pair<int, int> >, custom_hash> freq_2_station_number;
    int length = static_cast<int>(list_of_stations.size());
    for (int i = 0; i < length; ++i) {
        int stations_length = static_cast<int>(list_of_stations.at(i).size());
        for (int j = 0; j < stations_length; ++j) {
            freq_2_station_number[list_of_stations.at(i).at(j)].emplace_back(
                    make_pair(i, j));
        }
    }
    // Rename intersected stations from n + 1, except the station 1 and the station n
    int station_reindex = n + 1;
    for (const auto &[k, v_list] : freq_2_station_number) {
        if (v_list.size() > 1 && k != 1 && k != n) {
            for (const auto &[i, j] : v_list) {
                list_of_stations.at(i).at(j) = station_reindex;
                ++station_reindex;
            }
        }
    }
    // Add weighted edges
    int v_list_length;
    pair<int, int> station_i;
    pair<int, int> station_j;
    for (const auto &[k, v_list] : freq_2_station_number) {
        if (v_list.size() > 1 && k != 1 && k != n) {
            // add edges from any pair of nodes with weight of 1
            v_list_length = static_cast<int>(v_list.size());
            for (int i = 0; i < v_list_length - 1; ++i) {
                for (int j = i + 1; j < v_list_length; ++j) {
                    station_i = v_list.at(i);
                    station_j = v_list.at(j);
                    // v_list[i] -> v_list[j]
                    edges.emplace_back(
                            Edge(list_of_stations.at(station_i.first).at(
                                    station_i.second),
                                 list_of_stations.at(station_j.first).at(
                                         station_j.second),
                                 1));
                    // v_list[j] -> v_list[i]
                    edges.emplace_back(
                            Edge(list_of_stations.at(station_j.first).at(
                                    station_j.second),
                                 list_of_stations.at(station_i.first).at(
                                         station_i.second),
                                 1));
                }
            }
        }
    }
    // Add edges with zero weights
    for (const auto &i : list_of_stations) {
        if (i.size() > 1) {
            int stations_length = static_cast<int>(i.size());
            for (int j = 0; j < stations_length - 1; ++j) {
                edges.emplace_back(Edge(i.at(j), i.at(j + 1), 0));
            }
        }
    }
    int max_index_of_nodes = 1;
    for (const auto &[u, v, w] : edges) {
        max_index_of_nodes = max(max_index_of_nodes, max(u, v));
    }
    SSSP::init(max_index_of_nodes, static_cast<int>(edges.size()));
    SSSP::s = 1;
    for (const auto &[u, v, w] : edges) {
        SSSP::add_edge(u, v, w);
    }
    SSSP::dijkstra();
    if (SSSP::dis.at(n) == SSSP::INF) {
        cout << "NO" << '\n';
    } else {
        cout << SSSP::dis.at(n) << '\n';
    }
    return 0;
}
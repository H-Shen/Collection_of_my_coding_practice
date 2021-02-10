// https://open.kattis.com/problems/rainbowroadrace

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

constexpr int MAX_STATES = 128;
unordered_map<char, int> color2pos;

// set the 'pos'th bit of data to 1
int setBit(int data, int pos) {
    data |= (1<<pos);
    return data;
}

struct Node {
    int w, pos;
    Node(int d, int pos) : w(d), pos(pos) {}
    Node() = default;
};

struct Node2 {
    int d, status;
    Node2(int d, int status) : d(d), status(status) {}
    Node2() = default;
};

struct Comparator {
    bool operator () (const pair<Node2, int> &l, const pair<Node2, int> &r) {
        return make_pair(l.first.d, l.second) > make_pair(r.first.d, r.second);
    }
};

namespace SSSP_Dijkstra {
    constexpr int INF = 0x3f3f3f3f;
    // The adjacency list of the graph
    vector<vector<pair<int, Node> > > adj;
    int number_of_nodes;
    vector<vector<int> > dist;

    void
    init(int n) {
        number_of_nodes = n;
        adj.resize(number_of_nodes);
        dist.resize(number_of_nodes, vector<int>(MAX_STATES, INF));
    }
    void
    dijkstra(int source) {
        dist.at(source).at(0) = 0;
        std::priority_queue<pair<Node2, int>, vector<pair<Node2, int> >, Comparator > pq;
        pq.push(make_pair(Node2(0, 0), source));
        while (!pq.empty()) {
            int d_v = pq.top().first.d;
            int current_status = pq.top().first.status;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dist.at(v).at(current_status)) {
                continue;
            }
            for (const auto &i : adj.at(v)) {
                int next_status = setBit(current_status, i.second.pos);
                int weight = i.second.w;
                int to = i.first;
                if (dist.at(to).at(next_status) > dist.at(v).at(current_status) + weight) {
                    dist.at(to).at(next_status) = dist.at(v).at(current_status) + weight;
                    pq.push({Node2(dist.at(to).at(next_status), next_status), to});
                }
            }
        }
    }
}

int n, m, s, u, v, d;
char ch;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str = "ROYGBIV";
    for (int i = 0; i < (int)str.size(); ++i) color2pos[str[i]] = i;

    cin >> n >> m;
    s = 1;
    SSSP_Dijkstra::init(n + 5);
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> d >> ch;
        SSSP_Dijkstra::adj.at(u).emplace_back(v, Node(d, color2pos[ch]));
        SSSP_Dijkstra::adj.at(v).emplace_back(u, Node(d, color2pos[ch]));
    }
    SSSP_Dijkstra::dijkstra(s);
    cout << SSSP_Dijkstra::dist.at(s).at(MAX_STATES - 1) << '\n';

    return 0;
}

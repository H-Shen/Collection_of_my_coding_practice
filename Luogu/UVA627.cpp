#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

constexpr int MAXN = 100005;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

namespace SSSP {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > adj;
    vector<int> dist;
    vector<int> pre;
    int number_of_nodes;
    void init(int n) {
        decltype(adj)().swap(adj);
        number_of_nodes = n;
        adj.resize(number_of_nodes + 5);
    }
    void dijkstra(int source) {
        decltype(dist)().swap(dist);
        decltype(pre)().swap(pre);
        dist.resize(number_of_nodes + 5, INF);
        pre.resize(number_of_nodes + 5, -1);
        dist.at(source) = 0;
        // {dist[to], to}
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({dist.at(source), source});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int dist_u = cur.first;
            int u = cur.second;
            if (dist.at(u) < dist_u) continue;
            for (const auto &v : adj.at(u)) {
                // keep the lexicalgraphically smallest path
                if (dist.at(u) + 1 < dist.at(v)) {
                    dist.at(v) = dist.at(u) + 1;
                    pq.push({dist.at(v), v});
                    pre.at(v) = u;
                }
                else if (dist.at(u) + 1 == dist.at(v)) {
                    pre.at(v) = min(pre.at(v), u);
                }
            }
        }
    }
}

const regex r("[0-9]+");
void parse(const string &s) {
    int u = -1;
    int v;
    for (sregex_iterator it(s.begin(), s.end(), r), e; it != e; ++it) {
        if (u == -1) {
            u = stoi(it->str());
        }
        else {
            v = stoi(it->str());
            SSSP::adj.at(u).emplace_back(v);
        }
    }
}
vector<int> get_path(int dest, const vector<int> &pre) {
    vector<int> result;
    for (int u = dest; u != -1; u = pre.at(u)) {
        result.emplace_back(u);
    }
    reverse(result.begin(), result.end());
    return result;
}

int n, m, src, dest;

int main() {

    fast_io();
    while (cin >> n) {
        SSSP::init(n);
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            parse(s);
        }
        cin >> m;
        cout << "-----" << '\n';
        vector<vector<int> > pre(n + 5);
        vector<vector<int> > dist(n + 5);
        while (m--) {
            cin >> src >> dest;
            if (dist.at(src).empty()) {
                SSSP::dijkstra(src);
                dist.at(src) = SSSP::dist;
                pre.at(src) = SSSP::pre;
            }
            if (dist.at(src).at(dest) == SSSP::INF) {
                cout << "connection impossible" << '\n';
            } else {
                vector<int> path = get_path(dest, pre.at(src));
                cout << path.front();
                int length = (int) path.size();
                for (int i = 1; i < length; ++i) {
                    cout << ' ' << path.at(i);
                }
                cout << '\n';
            }
        }
    }

    return 0;
}
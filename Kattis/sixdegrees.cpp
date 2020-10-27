// https://open.kattis.com/problems/sixdegrees
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr double eps = 1e-7;
inline int sgn(const double &x) {
    if (x > eps) return 1;
    if (x > -eps) return 0;
    return -1;
}

constexpr int MAXN = 3005;
constexpr int DEPTH = 6;

gp_hash_table<string, int> node2id;
bitset<MAXN> vis[MAXN]; // vis[i][j] = true: start bfs from i and j is visited in this bfs
array<vector<int>, MAXN> adj;
int id;

struct Node {
    explicit Node(int val, int step) : val(val), step(step) {}
    int val;
    int step;
};
void bfs(Node u) {
    int start_index = u.val;
    queue<Node> q;
    q.push(u);
    vis[start_index][start_index] = true;
    while (!q.empty()) {
        u = q.front();
        if (u.step == DEPTH) {
            return;
        }
        q.pop();
        for (const auto &v : adj.at(u.val)) {
            if (!vis[start_index][v]) {
                vis[start_index][v] = true;
                q.push(Node(v, u.step + 1));
            }
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t, m, u, v;
    cin >> t;
    string a, b;
    while (t--) {
        cin >> m;
        while (m--) {
            cin >> a >> b;
            if (node2id.find(a) == node2id.end()) {
                node2id[a] = id;
                u = id;
                ++id;
            } else {
                u = node2id[a];
            }
            if (node2id.find(b) == node2id.end()) {
                node2id[b] = id;
                v = id;
                ++id;
            } else {
                v = node2id[b];
            }
            adj.at(u).emplace_back(v);
            adj.at(v).emplace_back(u);
        }
        // bfs from all nodes
        for (int i = 0; i < id; ++i) {
            bfs(Node(i, 0));
        }
        // calculate and output
        bitset<MAXN> reachable_vertices;
        reachable_vertices.flip();
        for (int i = 0; i < id; ++i) {
            reachable_vertices &= vis[i];
        }
        int counter_of_unreachable_vertices = 0;
        for (int i = 0; i < id; ++i) {
            if (!reachable_vertices[i]) {
                ++counter_of_unreachable_vertices;
            }
        }
        double rate = counter_of_unreachable_vertices * 1.0 / id;
        if (sgn(rate - 0.05) <= 0) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        // reset
        node2id.clear();
        id = 0;
        for (auto &i : adj) {
            vector<int>().swap(i);
        }
        for (auto &i : vis) {
            i.reset();
        }
    }
    return 0;
}

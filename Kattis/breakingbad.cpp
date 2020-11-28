// https://open.kattis.com/problems/breakingbad
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace BipartiteCheck {
    constexpr int INF = 0x3f3f3f3f;
    vector<int> color;
    vector<vector<int> > adj;
    int n;
    void init(int number_of_nodes) {
        n = number_of_nodes;
        decltype(adj)().swap(adj);
        decltype(color)().swap(color);
        adj.resize(n + 5);
        color.resize(n + 5, INF);
    }
    bool bfs() {
        queue<int> q;
        for (int s = 0; s < n; ++s) {
            if (color[s] == INF) {
                color[s] = 0;
                q.push(s);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const auto &v : adj[u]) {
                    if (color[v] == INF) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

unordered_map<string, int> name2id;
vector<string> id2name;
int n;

int main() {

    fast_io();
    cin >> n;
    BipartiteCheck::init(n);
    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        name2id[s] = i;
        id2name.emplace_back(s);
    }
    int m, u, v;
    string a, b;
    cin >> m;
    while (m--) {
        cin >> a >> b;
        u = name2id[a];
        v = name2id[b];
        BipartiteCheck::adj.at(u).emplace_back(v);
        BipartiteCheck::adj.at(v).emplace_back(u);
    }
    if (BipartiteCheck::bfs()) {
        vector<string> A, B;
        for (int i = 0; i < n; ++i) {
            if (BipartiteCheck::color.at(i)) {
                A.emplace_back(id2name.at(i));
            } else {
                B.emplace_back(id2name.at(i));
            }
        }
        bool firstItem = true;
        for (const auto &i : A) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
        cout << '\n';
        firstItem = true;
        for (const auto &i : B) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << i;
        }
        cout << '\n';
    } else {
        cout << "impossible" << '\n';
    }

    return 0;
}

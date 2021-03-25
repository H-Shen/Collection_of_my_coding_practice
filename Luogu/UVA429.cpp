#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<int> > adj;
int u, v, len;

int bfs(int source, int dest) {
    constexpr int INF = 0x3f3f3f3f;
    vector<int> dist(len + 5, INF);
    dist[source] = 0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == dest) break;
        for (const auto &v_ : adj[cur]) {
            if (dist[v_] == INF) {
                dist[v_] = dist[cur] + 1;
                q.push(v_);
            }
        }
    }
    return dist[dest];
}

bool check(const string &a, const string &b) {
    if (a.size() != b.size()) return false;
    int counter = 0;
    for (size_t i = 0; i != a.size(); ++i) {
        if (a[i] != b[i]) {
            ++counter;
            if (counter > 1) return false;
        }
    }
    return counter == 1;
}

int main() {

    fast_io();
    int n;
    cin >> n;
    string s, s1, s2;
    bool firstCase = true;
    while (n--) {
        vector<string> words;
        unordered_map<string, int> node2id;
        int id = 0;
        while (true) {
            cin >> s;
            if (s == "*") break;
            if (node2id.find(s) != node2id.end()) continue;
            node2id[s] = id;
            ++id;
            words.emplace_back(s);
        }
        // create the graph
        len = (int)words.size();
        decltype(adj)().swap(adj);
        adj.resize(len + 5);
        for (int i = 0; i < len - 1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                if (check(words[i], words[j])) {
                    u = node2id[words[i]];
                    v = node2id[words[j]];
                    adj[u].emplace_back(v);
                    adj[v].emplace_back(u);
                }
            }
        }
        cin.get();
        if (firstCase) firstCase = false;
        else cout << '\n';
        while (true) {
            if (!getline(cin, s) || s.empty()) break;
            istringstream iss(s);
            iss >> s1 >> s2;
            cout << s1 << ' ' << s2 << ' ' << bfs(node2id[s1], node2id[s2]) << '\n';
        }
    }


    return 0;
}
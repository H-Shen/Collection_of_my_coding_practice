#include <bits/stdc++.h>

using namespace std;
using ll = long long;

unordered_map<string, int> node2id;
vector<string> id2node;
vector<vector<int> > AL;
vector<int> pre;
int id;
vector<bool> vis;

int bfs(int source, int dest) {
    queue<int> q;
    vector<int> dist(id, -1);
    q.push(source);
    dist.at(source) = 0;
    int u;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        if (u == dest) {
            return dist.at(u);
        }
        for (const auto &v : AL.at(u)) {
            if (dist.at(v) == -1) {
                dist.at(v) = dist.at(u) + 1;
                pre.at(v) = u;
                q.push(v);
            }
        }
    }
    return dist.at(dest);
}

void dfs(string s) {
    int u, v;
    u = node2id[s];
    if (vis.at(u)) return;
    vis.at(u) = true;
    char original;
    for (size_t i = 0; i != s.size(); ++i) {
        original = s.at(i);
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (ch != original) {
                s.at(i) = ch;
                if (node2id.find(s) != node2id.end()) {
                    v = node2id[s];
                    dfs(s);
                    AL.at(u).emplace_back(v);
                }
            }
        }
        s.at(i) = original;
    }
}

void print_path(int v) {
    vector<int> vec;
    for (; v != -1; v = pre.at(v)) {
        vec.emplace_back(v);
    }
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        cout << id2node[*it] << '\n';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    while (true) {
        getline(cin, s);
        if (s.empty()) break;
        if (node2id.find(s) == node2id.end()) {
            node2id[s] = id;
            ++id;
            id2node.emplace_back(s);
        }
    }
    vis.resize(id);
    AL.resize(id);
    for (int i = 0; i < id; ++i) {
        if (!vis.at(i)) {
            dfs(id2node.at(i));
        }
    }
    int u, v, ans;
    bool first_case = true;
    while (true) {
        if (!(cin >> s)) break;
        u = node2id[s];
        cin >> s;
        v = node2id[s];
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        // Corner case
        if (u == v) {
            cout << s << '\n';
            continue;
        }
        vector<int>().swap(pre);
        pre.resize(id, -1);
        ans = bfs(u, v);
        if (ans == -1) {
            cout << "No solution." << '\n';
        } else {
            print_path(v);
        }
    }

    return 0;
}
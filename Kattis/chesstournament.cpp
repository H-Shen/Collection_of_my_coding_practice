// https://open.kattis.com/problems/chesstournament
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n+5,1);
    }
    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

int n,m,u,v;
string op;
vector<pair<int,int>> edges;
vector<vector<int>> adj;
vector<int> inDegree;

bool kahn(int nodes) {
    queue<int> q;
    int cnt = 0;
    for (int i = 0; i < nodes; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    int temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        ++cnt;
        for (const auto &i : adj[temp]) {
            --inDegree[i];
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return cnt == nodes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    DSU::init(n);
    while (m--) {
        cin >> u >> op >> v;
        if (op[0] == '=') {
            DSU::merge(u, v);
        }
        else {
            edges.emplace_back(u,v);
        }
    }
    // contract vertices
    int root;
    for (auto&[i,j] : edges) {
        root = DSU::find(i);
        if (root != i) {
            i = root;
        }
        root = DSU::find(j);
        if (root != j) {
            j = root;
        }
        // self cycle
        if (i == j) {
            cout << "inconsistent" << '\n';
            return 0;
        }
    }
    // reorder node IDs
    unordered_map<int,int> old2new;
    for (auto&[i,j] : edges) {
        if (old2new.count(i) == 0) {
            old2new[i] = (int)old2new.size();
        }
        if (old2new.count(j) == 0) {
            old2new[j] = (int)old2new.size();
        }
    }
    // create the graph
    int length = (int)old2new.size();
    adj.resize(length);
    inDegree.resize(length);
    for (auto&[i,j] : edges) {
        u = old2new[i];
        v = old2new[j];
        adj[u].emplace_back(v);
        ++inDegree[v];
    }
    if (kahn(length)) {
        cout << "consistent" << '\n';
    }
    else {
        cout << "inconsistent" << '\n';
    }
    return 0;
}


// https://open.kattis.com/problems/guilds

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

constexpr int MAXN = 2*1e5+5;

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
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x,y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

int id = 0;
bitset<MAXN> hasOutDeg;
int m,u,v;
string str_u,str_v;
unordered_map<string,int> node2id;
vector<string> id2node;
vector<pair<int,int>> edges;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    DSU::init(MAXN);
    cin >> m;
    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> str_u >> str_v;
        if (node2id.count(str_u) == 0) {
            node2id[str_u] = id;
            id2node.emplace_back(str_u);
            u = id;
            ++id;
        }
        else {
            u = node2id[str_u];
        }
        if (node2id.count(str_v) == 0) {
            node2id[str_v] = id;
            id2node.emplace_back(str_v);
            v = id;
            ++id;
        }
        else {
            v = node2id[str_v];
        }
        DSU::merge(u,v);
        hasOutDeg[u] = true;
        edges[i].first = u;
        edges[i].second = v;
    }
    vector<int> father2root(id);
    for (int i = 0; i < id; ++i) {
        if (!hasOutDeg[i]) {
            father2root[DSU::find(i)] = i;
        }
    }
    // output
    for (int i = 0; i < m; ++i) {
        u = edges[i].first;
        cout << id2node[u] << ' ' << id2node[father2root[DSU::find(u)]] << '\n';
    }
    return 0;
}

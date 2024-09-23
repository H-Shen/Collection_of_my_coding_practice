#include <bits/extc++.h>

using namespace std;

vector<vector<int> > AL;
int n, u, v;

namespace DSU {
    vector<int> father, Size;
    int cc;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
        cc = n;
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x,y);
        Size[y] += Size[x];
        father[x] = y;
        --cc;
    }
}

namespace Ecc {
    vector<int> edged, maxDist;
    void init() {
        vector<int>().swap(edged);
        vector<int>().swap(maxDist);
        edged.resize(n+1,-1);
        maxDist.resize(n+1);
    }
    int dfs1(int u, int fa) {
        edged[u] = 0;
        for (const auto &v : AL[u]) {
            if (v != fa) {
                edged[u] = max(edged[u],1+dfs1(v,u));
            }
        }
        return edged[u];
    }
    void dfs2(int u, int fa, int pd) {
        int maxEdges[] = {pd, 0};
        int nwmg = 1;
        for (const auto &v : AL[u]) {
            if (v != fa) {
                if (edged[v]+1>maxEdges[0]) {
                    maxEdges[1] = maxEdges[0];
                    maxEdges[0] = edged[v]+1;
                    nwmg = 1;
                }
                else if (edged[v]+1==maxEdges[0]) {
                    ++nwmg;
                }
                else if (edged[v]+1>maxEdges[1]) {
                    maxEdges[1]=edged[v]+1;
                }
            }
        }
        for (const auto &v : AL[u]) {
            if (v != fa) {
                int upd = maxEdges[0];
                if (upd == edged[v]+1 && nwmg == 1) {
                    upd = maxEdges[1];
                }
                dfs2(v,u,upd+1);
            }
        }
        maxDist[u]=max(pd,maxEdges[0]);
    }
    void run() {
        for (int i = 1; i <= n; ++i) {
            if (edged[i] == -1) {
                dfs1(i,-1);
                dfs2(i,-1,0);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    decltype(AL)().swap(AL);
    cin >> n;
    AL.resize(n+1);
    DSU::init(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        DSU::merge(u,v);
        AL[u].emplace_back(v);
        AL[v].emplace_back(u);
    }
    if (DSU::cc != 1) {
        cout << "Error: " << DSU::cc << " components" << '\n';
        return 0;
    }
    Ecc::init();
    Ecc::run();
    int depth = *max_element(Ecc::maxDist.begin()+1,Ecc::maxDist.end());
    for (int i = 1; i <= n; ++i) {
        if (Ecc::maxDist[i] == depth) {
            cout << i << '\n';
        }
    }
    
    return 0;
}

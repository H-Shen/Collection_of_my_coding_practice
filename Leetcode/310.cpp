// The maximum distances from every vertex are stored in maxDist[]
// Time cost: O(n)
namespace Eccentricity {
    vector<vector<int> > AL;
    int n;
    vector<int> edged, maxDist;
    void init(int n_) {
        n = n_;
        decltype(AL)().swap(AL);
        vector<int>().swap(edged);
        vector<int>().swap(maxDist);
        edged.resize(n,-1);
        maxDist.resize(n);
        AL.resize(n);
    }
    // Obtain the longest path from the subtree with u as root to its leaves
    int dfs1(int u, int fa) {
        edged[u] = 0;
        for (const auto &v : AL[u]) {
            if (v == fa) {
                continue;
            }
            edged[u] = max(edged[u],1+dfs1(v,u));
        }
        return edged[u];
    }
    void dfs2(int u, int fa, int pd) {
        int maxEdges[2] = {pd,0};
        int nwmg = 1;
        for (const auto &v : AL[u]) {
            if (v == fa) {
                continue;
            }
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
        for (const auto &v : AL[u]) {
            if (v == fa) {
                continue;
            }
            int upd = maxEdges[0];
            if (upd == edged[v]+1 && nwmg == 1) {
                upd = maxEdges[1];
            }
            dfs2(v,u,upd+1);
        }
        maxDist[u] = max(pd, maxEdges[0]);
    }
    void run() {
        for (int i = 0; i < n; ++i) {
            if (edged[i] == -1) {
                dfs1(i,-1);
                dfs2(i,-1,0);
            }
        }
    }
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        Eccentricity::init(n);
        int u,v;
        for (const auto &i : edges) {
            u = i[0];
            v = i[1];
            Eccentricity::AL[u].emplace_back(v);
            Eccentricity::AL[v].emplace_back(u);
        }
        Eccentricity::run();
        vector<int> ans;
        int minVal = *min_element(Eccentricity::maxDist.begin(), Eccentricity::maxDist.end());
        for (int i = 0; i < n; ++i) {
            if (Eccentricity::maxDist[i] == minVal) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};
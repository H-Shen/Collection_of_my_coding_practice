constexpr int MAXN = 1e5+5;
constexpr int INF = 0x3f3f3f3f;

using ll = long long;

vector<int> adj[MAXN];
int Size[MAXN];
ll ans[MAXN];
int n;

int dp(int u) {
    if (Size[u] != INF) return Size[u];
    Size[u] = 1;
    for (auto &v : adj[u]) {
        Size[u] += dp(v);
    }
    return Size[u];
}

ll getScore(int u) {
    ll score = 1;
    for (auto &v : adj[u]) {
        score *= (ll)dp(v);
    }
    // check if u is root
    if (u != 0) {
        score *= (ll)(n-dp(u));
    }
    return score;
}

void dfs(int u) {
    ans[u] = getScore(u);
    for (auto &v : adj[u]) {
        dfs(v);
    }
}


class Solution {
public:
    int countHighestScoreNodes(vector<int>& parents) {
        memset(adj, 0, sizeof adj);
        memset(ans, 0, sizeof ans);
        n = (int)parents.size();
        int u, v;
        for (int i = 0; i < n; ++i) {
            u = parents[i];
            v = i;
            if (u != -1) {
                adj[u].emplace_back(v);
            }
        }
        memset(Size, 0x3f, sizeof Size);
        dfs(0);
        ll highest = *max_element(ans,ans+n);
        return (int)count(ans,ans+n,highest);
    }
};
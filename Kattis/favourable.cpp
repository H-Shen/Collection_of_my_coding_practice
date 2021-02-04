// https://open.kattis.com/problems/favourable
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX_LENGTH = 20;

char cstr[MAX_LENGTH];
unordered_map<int, unordered_set<int> > adj;

bool isdigit(const string &s) {
    for (const char &ch : s) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}

unordered_set<int> Nodes;

struct my_hash_func {
    size_t operator() (const pair<int, int> &obj) const {
        return hash<int>()(obj.first) ^ hash<int>()(obj.second);
    }
};
unordered_map<pair<int, int>, ll, my_hash_func> dp;

// dp[u][v] --> the number of paths from u to v
// dp[u][u] = 1
// dp[u][v] = Sum dp[adj of u][v]
ll dfs(int u, int v) {
    if (u == v) return 1;
    ll sum = 0;
    ll temp;
    for (const int u_adj : adj[u]) {
        if (dp.find({u_adj, v}) != dp.end()) {
            sum += dp[{u_adj, v}];
        }
        else {
            temp = dfs(u_adj, v);
            sum += temp;
        }
    }
    dp[{u, v}] = sum;
    return sum;
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {

        Nodes.clear();
        adj.clear();
        dp.clear();

        int s;
        int a, b, c, d;
        scanf("%d", &s);
        while (s--) {
            scanf("%d", &a);
            scanf("%s", cstr);
            if (isdigit(cstr)) {
                b = stoi(cstr);
                scanf("%d %d", &c, &d);
                adj[a].insert(b);
                adj[a].insert(c);
                adj[a].insert(d);
            } else {
                if (strcmp(cstr, "favourably") == 0) {
                    Nodes.insert(a);
                }
            }
        }
        ll sum = 0;
        for (const int &v : Nodes) {
            sum += dfs(1, v);
        }
        printf("%lld\n", sum);
    }
    return 0;
}

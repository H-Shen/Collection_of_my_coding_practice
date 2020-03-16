// https://open.kattis.com/problems/pachinkoprobability
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct my_hash_func {
    size_t operator()(const pair<int, int> &obj) const {
        return hash<int>()(obj.first) ^ hash<int>()(obj.second);
    }
};

unordered_map<int, unordered_set<int> > adj;
unordered_map<pair<int, int>, ll, my_hash_func> dfs_count;

ll dfs(int u, int v) {
    if (u == v) {
        return 1;
    }
    ll sum = 0;
    ll temp;
    for (const int u_adj : adj[u]) {
        if (dfs_count.find({u_adj, v}) != dfs_count.end()) {
            sum += dfs_count[{u_adj, v}];
        } else {
            temp = dfs(u_adj, v);
            sum += temp;
            dfs_count[{u_adj, v}] = temp;
        }
    }
    dfs_count[{u, v}] = sum;
    return sum;
}


int main() {

    int n;
    scanf("%d", &n);
    vector<bool> has_father(n, false);
    vector<bool> has_children(n, false);
    int m;
    scanf("%d", &m);
    int u, v;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].insert(v);
        has_father.at(v) = true;
        has_children.at(u) = true;
    }
    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if (!has_father.at(i)) {
            roots.emplace_back(i);
        }
    }
    unordered_set<int> other_leaves;
    for (int i = 0; i < n; ++i) {
        if (!has_children.at(i)) {
            other_leaves.insert(i);
        }
    }
    unordered_set<int> win_leaves;
    int k;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &u);
        win_leaves.insert(u);
        other_leaves.erase(u);
    }


    // count win paths
    ll sum_win = 0;
    for (const int &u_ : roots) {
        for (const int &v_ : win_leaves) {
            sum_win += dfs(u_, v_);
        }
    }
    // count all paths
    ll sum = sum_win;
    for (const int &u_ : roots) {
        for (const int &v_ : other_leaves) {
            sum += dfs(u_, v_);
        }
    }
    printf("winning paths %lld\n", sum_win);
    printf("total paths %lld\n", sum);
    return 0;
}


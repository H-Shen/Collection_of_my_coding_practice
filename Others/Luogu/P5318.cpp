// Cover the basic concepts of BFS and DFS on a graph
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_map<int, vector<int> > E;

vector<bool> vis;
vector<int> dfs_output;
void dfs(int id) {
    if (vis.at(id)) {
        return;
    }
    vis.at(id) = true;
    dfs_output.emplace_back(id);
    for (const int &adj_id : E[id]) {
        dfs(adj_id);
    }
}

vector<int> bfs_output;
void bfs(int id) {
    queue<int> q;
    q.push(id);
    bfs_output.emplace_back(id);
    vis.at(id) = true;
    while (!q.empty()) {
        int current_id = q.front();
        q.pop();
        for (const int &adj_id : E[current_id]) {
            if (!vis.at(adj_id)) {
                q.push(adj_id);
                bfs_output.emplace_back(adj_id);
                vis.at(adj_id) = true;
            }
        }
    }
}

int main() {

    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        E[u].emplace_back(v);
    }
    for (auto &[k, v] : E) {
        sort(v.begin(), v.end());
    }
    vector<bool>().swap(vis);
    vis.resize(n + 5, false);
    dfs(1);
    vector<bool>().swap(vis);
    vis.resize(n + 5, false);
    bfs(1);

    // output
    bool first_item;
    // dfs
    first_item = true;
    for (const auto &i : dfs_output) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");
    //bfs
    first_item = true;
    for (const auto &i : bfs_output) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");
    return 0;
}

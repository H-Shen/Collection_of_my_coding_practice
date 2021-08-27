/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

constexpr int MAXN = 2005;

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int id2importance[MAXN];
    vector<int> adj[MAXN];
    int sumOfImportance = 0;
    void dfs(int u) {
        sumOfImportance += id2importance[u];
        for (const auto &i : adj[u]) {
            dfs(i);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (const auto &e : employees) {
            id2importance[e->id] = e->importance;
            for (const auto &i : e->subordinates) {
                adj[e->id].emplace_back(i);
            }
        }
        dfs(id);
        return sumOfImportance;
    }
};
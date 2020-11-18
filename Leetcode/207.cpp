namespace Toposort {

    unordered_map<int, unordered_set<int> > adj;
    int number_of_nodes;
    vector<int> in_degree;

    inline
    void reset() {
        adj.clear();
        vector<int>().swap(in_degree);
        number_of_nodes = 0;
    }

    inline
    void init(int n) {
        number_of_nodes = n;
        in_degree.resize(n + 5);
    }

    inline
    bool kahn() {
        int counter = 0;
        queue<int> q;
        for (int i = 1; i <= number_of_nodes; ++i) {
            if (in_degree.at(i) == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ++counter;
            for (const auto &adj_v : adj[u]) {
                --in_degree.at(adj_v);
                if (in_degree.at(adj_v) == 0) {
                    q.push(adj_v);
                }
            }
        }
        return (counter == number_of_nodes);
    }
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Toposort::reset();
        Toposort::init(numCourses);
        int u, v;
        for (const auto &i : prerequisites) {
            u = i.front() + 1;
            v = i.back() + 1;
            Toposort::adj[u].insert(v);
            ++Toposort::in_degree.at(v);
        }
        return Toposort::kahn();
    }
};
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

namespace Toposort {
    // adjacency list of the graph
    vector<vector<int> > AL;
    int number_of_nodes;    // assume that the node id starts from 1
    // the number of incoming edges of each node, should be calculated during
    // the construction of the graph, not forget that the node id starts from 1
    vector<int> in_degree;
    vector<int> result; // store the result after toposort
    vector<bool> vis;
    void init(int n) {
        number_of_nodes = n;
        in_degree.resize(n);
        AL.resize(n);
        vis.resize(n, false);
    }
    // return 1: there exist more than 1 node such that its in degree == 0
    // return 0: the relationship can be confirmed
    // return -1: there is a cycle
    int kahn() {
        queue<int> q;
        vector<int> in_degree_copy = in_degree;
        for (int i = 0; i < number_of_nodes; ++i) {
            if (in_degree_copy.at(i) == 0) {
                q.push(i);
            }
        }
        bool not_confirmed = false;
        vector<int>().swap(result);
        while (!q.empty()) {
            if (q.size() > 1) {
                not_confirmed = true;
            }
            int u = q.front();
            q.pop();
            result.emplace_back(u);
            for (const auto &adj_v : AL[u]) {
                --in_degree_copy.at(adj_v);
                if (in_degree_copy.at(adj_v) == 0) {
                    q.push(adj_v);
                }
            }
        }
        if ((int)result.size() != number_of_nodes) {
            return -1;
        }
        if (not_confirmed) {
            return 1;
        }
        return 0;
    }
}

int n, m, u, v;


int main() {

    fast_io();
    string s;
    cin >> n >> m;
    Toposort::init(n);
    for (int i = 1; i <= m; ++i) {
        cin >> s;
        u = s.front() - 'A';
        v = s.back() - 'A';
        Toposort::vis.at(u) = true;
        Toposort::vis.at(v) = true;
        // u->v
        ++Toposort::in_degree.at(v);
        Toposort::AL.at(u).emplace_back(v);
        int temp = Toposort::kahn();
        if (temp == 0) {
            bool accessAllNodes = true;
            for (const auto &j : Toposort::vis) {
                if (!Toposort::vis.at(j)) {
                    accessAllNodes = false;
                    break;
                }
            }
            if (accessAllNodes) {
                cout << "Sorted sequence determined after " << i << " relations: ";
                for (const auto &ch : Toposort::result) {
                    cout << (char) (ch + 'A');
                }
                cout << '.' << '\n';
                return 0;
            }
        }
        else if (temp == -1) {
            cout << "Inconsistency found after " << i << " relations." << '\n';
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." << '\n';

    return 0;
}
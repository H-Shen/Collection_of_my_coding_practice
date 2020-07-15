// https://open.kattis.com/problems/secretchamber
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 26;

// An implementation of Floyd Warshall Algorithm to obtain the transitive closure of a directed-graph in O(N^3)
inline vector<vector<bool> >
floyd_warshall(int n, const vector<vector<bool> > &adjacency_matrix) {
    vector<vector<bool> > reach(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // If there is an edge between i and j, that is, adjacency_matrix[i][j] is true, then we make its weight as 1 in 'reach'
            if (adjacency_matrix.at(i).at(j)) {
                reach.at(i).at(j) = true;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is true
                reach.at(i).at(j) = reach.at(i).at(j) ||
                                    (reach.at(i).at(k) && reach.at(k).at(j));
            }
        }
    }
    return reach;
}

inline
bool can_be_converted(const string &lhs, const string &rhs,
                      const vector<vector<bool> > &transitive_closure) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (size_t i = 0; i != lhs.size(); ++i) {
        if (!transitive_closure.at(lhs.at(i) - 'a').at(rhs.at(i) - 'a')) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int m, n;
    string a, b;
    cin >> m >> n;
    vector<vector<bool> > adj(MAXN, vector<bool>(MAXN, false));
    // Add self to self
    for (int i = 0; i < MAXN; ++i) {
        adj.at(i).at(i) = true;
    }
    // Add other edges
    while (m--) {
        cin >> a >> b;
        adj.at(a.front() - 'a').at(b.front() - 'a') = true;
    }
    vector<vector<bool> > transitive_closure = floyd_warshall(MAXN, adj);
    while (n--) {
        cin >> a >> b;
        if (can_be_converted(a, b, transitive_closure)) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}

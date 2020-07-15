// https://open.kattis.com/problems/isahasa
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 505;

// An implementation of Floyd Warshall Algorithm to obtain the transitive closure of a directed-graph in O(N^3 / w) with bitset optimized
template<size_t N>
struct TransitiveClosure {
    bitset<N> reach[N];

    void floyd_warshall(int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];    // reach[i] = reach[i] | reach[k];
                }
            }
        }
    }
};

TransitiveClosure<MAXN> is_a, has_a;
int node_id;    // count from 0
unordered_map<string, int> node_name_2_node_id;
vector<pair<int, int> > has_a_relationships_from_input;

int main(int argc, char *argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, u, v, w;
    string lhs, relationship, rhs;
    decltype(node_name_2_node_id)::const_iterator iter;
    cin >> n >> m;
    while (n--) {
        cin >> lhs >> relationship >> rhs;
        // add nodes
        iter = node_name_2_node_id.find(lhs);
        if (iter == node_name_2_node_id.end()) {
            node_name_2_node_id[lhs] = node_id;
            u = node_id;
            ++node_id;
        } else {
            u = iter->second;
        }
        iter = node_name_2_node_id.find(rhs);
        if (iter == node_name_2_node_id.end()) {
            node_name_2_node_id[rhs] = node_id;
            v = node_id;
            ++node_id;
        } else {
            v = iter->second;
        }
        // update the matrix
        if (relationship == "is-a") {
            is_a.reach[u][v] = true;    // Case 1: u is-a v
        } else {
            has_a.reach[u][v] = true;   // Case 2: u has-a v
            has_a_relationships_from_input.emplace_back(make_pair(u, v));
        }
    }
    // Case 3: u is-a u
    for (u = 0; u < node_id; ++u) {
        is_a.reach[u][u] = true;
    }
    // Case 4: if u is-a v, v is-a w, then u is-a w
    is_a.floyd_warshall(node_id);
    // Case 5: if u has-a v, v is-a w, then u has-a w
    for (const auto &i : has_a_relationships_from_input) {
        u = i.first;
        v = i.second;
        for (w = 0; w < node_id; ++w) {
            if (is_a.reach[v][w]) {
                has_a.reach[u][w] = true;
            }
        }
    }
    // Case 6: if u is-a v, v has-a w, then u has-a w
    for (v = 0; v < node_id; ++v) {
        for (u = 0; u < node_id; ++u) {
            if (is_a.reach[u][v]) {
                has_a.reach[u] |= has_a.reach[v];
            }
        }
    }
    // Case 7: if u has-a v, v has-a w, then u has-a w
    has_a.floyd_warshall(node_id);

    // query
    for (int i = 1; i <= m; ++i) {
        cin >> lhs >> relationship >> rhs;
        cout << "Query " << i << ": ";
        u = node_name_2_node_id[lhs];
        v = node_name_2_node_id[rhs];
        if (relationship == "is-a") {
            if (is_a.reach[u][v]) {
                cout << "true";
            } else {
                cout << "false";
            }
        } else {
            if (has_a.reach[u][v]) {
                cout << "true";
            } else {
                cout << "false";
            }
        }
        cout << '\n';
    }

    return 0;
}

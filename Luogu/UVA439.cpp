#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

constexpr int SIZE = 8;
constexpr int STEPS = 8;
constexpr array<int, STEPS> dx = {1, 1, -1, -1, 2, 2, -2, -2};
constexpr array<int, STEPS> dy = {2, -2, 2, -2, -1, 1, -1, 1};

namespace APSP_Floyd_Warshall {

    constexpr int INF = 0x3f3f3f3f;

    vector<vector<int> > adj_matrix; // adjacency matrix
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<int> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes, vector<int>(number_of_nodes, INF));
        for (int i = 0; i < number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }

    inline
    void floyd_warshall() {
        for (int k = 0; k < number_of_nodes; ++k) {
            for (int i = 0; i < number_of_nodes; ++i) {
                for (int j = 0; j < number_of_nodes; ++j) {
                    if (adj_matrix.at(i).at(k) < INF &&
                        adj_matrix.at(k).at(j) < INF) {
                        adj_matrix.at(i).at(j) = min(adj_matrix.at(i).at(j),
                                                     adj_matrix.at(i).at(k) +
                                                     adj_matrix.at(k).at(j));
                    }
                }
            }
        }
    }

    // Query the shortest distance from node u to node v
    inline
    int dist(const int &u, const int &v) {
        return adj_matrix.at(u).at(
                v);  // INF: cant reach
    }
}

auto convert = [](const string &s) -> int {
    return (s.back() - '1') * SIZE + (s.front() - 'a');
};

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

int main() {

    fast_io();
    // pre
    APSP_Floyd_Warshall::init(SIZE * SIZE);
    int new_i, new_j, cur_pos, new_pos;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cur_pos = i * SIZE + j;
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                new_pos = new_i * SIZE + new_j;
                if (new_i >= 0 && new_i < SIZE && new_j >= 0 && new_j < SIZE) {
                    APSP_Floyd_Warshall::adj_matrix.at(cur_pos).at(new_pos) = 1;
                    APSP_Floyd_Warshall::adj_matrix.at(new_pos).at(cur_pos) = 1;
                }
            }
        }
    }
    APSP_Floyd_Warshall::floyd_warshall();
    string a, b;
    while (cin >> a >> b) {
        cout << "To get from " << a << " to " << b << " takes "
             << APSP_Floyd_Warshall::dist(convert(a), convert(b))
             << " knight moves." << '\n';
    }
    
    return 0;
}

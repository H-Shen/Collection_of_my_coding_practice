#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;

int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

namespace APSP_Floyd_Warshall {

    constexpr double INF = 1e9;

    vector<vector<double> > adj_matrix; // adjacency matrix
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<double> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes,
                          vector<double>(number_of_nodes, INF));
        for (int i = 0; i < number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0.0;
        }
    }

    inline
    void floyd_warshall() {
        for (int k = 0; k < number_of_nodes; ++k) {
            for (int i = 0; i < number_of_nodes; ++i) {
                for (int j = 0; j < number_of_nodes; ++j) {
                    if (sgn(adj_matrix.at(i).at(k) - INF) < 0 &&
                        sgn(adj_matrix.at(k).at(j) - INF) < 0) {
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
    double dist(const int &u, const int &v) {
        return adj_matrix.at(u).at(
                v);  // INF: cant reach
    }
}

vector<pair<int, int> > stores;

inline
double dist(const pair<int, int> &l, const pair<int, int> &r) {
    return sqrt((l.first - r.first) * (l.first - r.first) +
                (l.second - r.second) * (l.second - r.second));
}

int main(int argc, char *argv[]) {

    int n;
    scanf("%d", &n);
    stores.resize(n);
    APSP_Floyd_Warshall::init(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &stores.at(i).first, &stores.at(i).second);
    }
    int m, u, v;
    double dis;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &u, &v);
        --u;
        --v;
        dis = dist(stores.at(u), stores.at(v));
        APSP_Floyd_Warshall::adj_matrix.at(u).at(v) = dis;
        APSP_Floyd_Warshall::adj_matrix.at(v).at(u) = dis;
    }
    int s, t;
    scanf("%d %d", &s, &t);
    --s;
    --t;
    APSP_Floyd_Warshall::floyd_warshall();
    printf("%.2lf\n", APSP_Floyd_Warshall::dist(s, t));

    return 0;
}
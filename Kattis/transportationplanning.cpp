// https://open.kattis.com/problems/transportationplanning
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

constexpr double EPS = 1e-7;
inline int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

namespace APSP_Floyd_Warshall {

    constexpr double INF = 0x3f3f3f3f3f;
    vector<vector<double> > adj_matrix, adj_matrix_after_floyd;
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<double> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes, vector<double>(number_of_nodes, INF));
        for (int i = 0; i < number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0.0;
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

    // Update
    void update(int node_id) {
        for (int i = 0; i < number_of_nodes; ++i) {
            for (int j = 0; j < number_of_nodes; ++j) {
                adj_matrix.at(i).at(j) = min(adj_matrix.at(i).at(j), adj_matrix.at(i).at(node_id) + adj_matrix.at(node_id).at(j));
            }
        }
    }

    // Query the shortest distance from node u to node v
    inline
    double get_sum() {
        double result = 0.0;
        for (int i = 0; i < number_of_nodes - 1; ++i) {
            for (int j = i + 1; j < number_of_nodes; ++j) {
                result += adj_matrix.at(i).at(j);
            }
        }
        return result;
    }
}

inline
double getDist(const pii &l, const pii &r) {
    return sqrt( (l.first-r.first)*(l.first-r.first) + (l.second-r.second)*(l.second-r.second) );
}

inline
bool cmp(const pair<pii, double> &l, const pair<pii, double> &r) {
    int tmp = sgn(l.second - r.second);
    if (tmp == 0) {
        if (l.first.first == r.first.first) {
            return (l.first.second < r.first.second);
        }
        return (l.first.first < r.first.first);
    }
    return tmp < 0;
}

constexpr int MAXN = 1005;
constexpr int OFFSET = 500;
bitset<MAXN> vis[MAXN];
int n, m, u, v;

int main() {

    while (true) {
        IO::read(n);
        if (n == 0) break;
        vector<pii> points(n);
        for (auto &[x, y] : points) {
            IO::read(x, y);
            vis[x + OFFSET][y + OFFSET] = true;
        }
        IO::read(m);
        APSP_Floyd_Warshall::init(n);
        double dist;
        while (m--) {
            IO::read(u, v);
            dist = getDist(points.at(u), points.at(v));
            APSP_Floyd_Warshall::adj_matrix.at(u).at(v) = dist;
            APSP_Floyd_Warshall::adj_matrix.at(v).at(u) = dist;
        }
        APSP_Floyd_Warshall::floyd_warshall();
        APSP_Floyd_Warshall::adj_matrix_after_floyd = APSP_Floyd_Warshall::adj_matrix;
        double original_sum = APSP_Floyd_Warshall::get_sum();

        vector<pair<pii, double> > output;
        double current_sum;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                u = i;
                v = j;
                if (!vis[u + OFFSET][v + OFFSET]) {
                    dist = getDist(points.at(u), points.at(v));
                    if (APSP_Floyd_Warshall::adj_matrix_after_floyd.at(u).at(v) > dist) {
                        APSP_Floyd_Warshall::adj_matrix = APSP_Floyd_Warshall::adj_matrix_after_floyd;
                        APSP_Floyd_Warshall::adj_matrix.at(u).at(v) = dist;
                        APSP_Floyd_Warshall::adj_matrix.at(v).at(u) = dist;
                        // update shortest paths such that each includes u or v
                        APSP_Floyd_Warshall::update(u);
                        APSP_Floyd_Warshall::update(v);
                        current_sum = APSP_Floyd_Warshall::get_sum();
                        if (sgn(original_sum - current_sum) > 0) {
                            output.push_back({{u, v}, current_sum});
                        }
                    }
                }
            }
        }
        if (output.empty()) {
            printf("no addition reduces %.8lf\n", original_sum);
        } else {
            auto min_val = *min_element(output.begin(), output.end(), cmp);
            printf("adding %d %d reduces %.8lf to %.8lf\n", min_val.first.first,
                   min_val.first.second, original_sum, min_val.second);
        }
        // reset
        for (auto &i : vis) {
            i.reset();
        }
    }

    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

struct City {
    pii a, b, c, d;
    double t;
};

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

constexpr double EPS = 1e-7;

inline
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

// Use gp_hash_table + custom hash function to accelerate
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};


namespace APSP_Floyd_Warshall {

    constexpr double INF = 1e7;
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
}

inline
bool is_right_angle(const pii &a, const pii &b, const pii &c) {
    return ((a.first - b.first) * (c.first - b.first) +
            (a.second - b.second) * (c.second - b.second) == 0);
}

inline
double dist(const pii &a, const pii &b) {
    return sqrt((a.first - b.first) * (a.first - b.first) +
                (a.second - b.second) * (a.second - b.second));
}

inline
pii get_the_4th_point_of_a_rec(const pii &a, const pii &b, const pii &c) {
    int x1, x2, x3, x4, y1, y2, y3, y4;
    if (is_right_angle(a, b, c)) {
        x1 = b.first;
        y1 = b.second;
        x2 = a.first;
        y2 = a.second;
        x3 = c.first;
        y3 = c.second;
    } else if (is_right_angle(a, c, b)) {
        x1 = c.first;
        y1 = c.second;
        x2 = a.first;
        y2 = a.second;
        x3 = b.first;
        y3 = b.second;
    } else {
        x1 = a.first;
        y1 = a.second;
        x2 = b.first;
        y2 = b.second;
        x3 = c.first;
        y3 = c.second;
    }
    x4 = x2 + x3 - x1;
    y4 = y2 + y3 - y1;
    return {x4, y4};
}

int n, s, t, A, B;
vector<City> city_list;

int main(int argc, char *argv[]) {

    IO::read(n);
    int number_of_nodes;
    double d;
    double result;
    while (n--) {
        IO::read(s, t, A, B);
        city_list.resize(s + 1);
        for (int i = 1; i <= s; ++i) {
            IO::read(city_list.at(i).a.first,
                     city_list.at(i).a.second,
                     city_list.at(i).b.first,
                     city_list.at(i).b.second,
                     city_list.at(i).c.first,
                     city_list.at(i).c.second,
                     city_list.at(i).t);
            city_list.at(i).d = get_the_4th_point_of_a_rec(city_list.at(i).a,
                                                           city_list.at(i).b,
                                                           city_list.at(i).c);
        }
        // Case 1: A = B, no need to move
        if (A == B) {
            result = 0.0;
        }
        // Case 2: A != B, query the shortest path from any station in A to any station in B
        else {
            // number all nodes from city_list[1] to city_list[s]
            unordered_map<pii, int, custom_hash> point2id;
            unordered_map<pii, int, custom_hash>::iterator iter;
            int counter = 0;
            for (int i = 1; i <= s; ++i) {
                vector<pii> stations{city_list.at(i).a, city_list.at(i).b,
                                     city_list.at(i).c, city_list.at(i).d};
                for (const auto &j : stations) {
                    iter = point2id.find(j);
                    if (iter == point2id.end()) {
                        point2id[j] = counter;
                        ++counter;
                    }
                }
            }
            APSP_Floyd_Warshall::init(counter);
            // add edges inside each city
            for (int i = 1; i <= s; ++i) {
                vector<pii> stations{city_list.at(i).a, city_list.at(i).b,
                                     city_list.at(i).c, city_list.at(i).d};
                number_of_nodes = 4;
                for (int j = 0; j < number_of_nodes - 1; ++j) {
                    for (int k = j + 1; k < number_of_nodes; ++k) {
                        d = dist(stations.at(j), stations.at(k)) *
                            city_list.at(i).t;
                        APSP_Floyd_Warshall::adj_matrix.at(
                                point2id[stations.at(j)]).at(
                                point2id[stations.at(k)]) = d;
                        APSP_Floyd_Warshall::adj_matrix.at(
                                point2id[stations.at(k)]).at(
                                point2id[stations.at(j)]) = d;
                    }
                }
            }
            // add edges from one city to another city
            for (int i = 1; i <= s - 1; ++i) {
                for (int j = i + 1; j <= s; ++j) {
                    vector<pii> stations_in_i{city_list.at(i).a,
                                              city_list.at(i).b,
                                              city_list.at(i).c,
                                              city_list.at(i).d};
                    vector<pii> stations_in_j{city_list.at(j).a,
                                              city_list.at(j).b,
                                              city_list.at(j).c,
                                              city_list.at(j).d};
                    for (const auto &station_i : stations_in_i) {
                        for (const auto &station_j : stations_in_j) {
                            d = dist(station_i, station_j) * t;
                            APSP_Floyd_Warshall::adj_matrix.at(
                                    point2id[station_i]).at(
                                    point2id[station_j]) = d;
                            APSP_Floyd_Warshall::adj_matrix.at(
                                    point2id[station_j]).at(
                                    point2id[station_i]) = d;
                        }
                    }
                }
            }
            // calculate
            APSP_Floyd_Warshall::floyd_warshall();
            result = APSP_Floyd_Warshall::INF;
            vector<pii> stations_in_A{city_list.at(A).a, city_list.at(A).b,
                                      city_list.at(A).c, city_list.at(A).d};
            vector<pii> stations_in_B{city_list.at(B).a, city_list.at(B).b,
                                      city_list.at(B).c, city_list.at(B).d};
            for (const auto &i : stations_in_A) {
                for (const auto &j : stations_in_B) {
                    result = min(result, APSP_Floyd_Warshall::adj_matrix.at(
                            point2id[i]).at(point2id[j]));
                }
            }
        }
        // output
        printf("%.1lf\n", result);
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr double WALK = 10*1000*1.0/60;
constexpr double SUBWAY = 4.0*WALK;

// An implementation of Floyd_Warshall Algorithm O(n^3) for finding
// all pairs of shortest path in a graph
namespace APSP {
    constexpr double INF = 0x3f3f3f3f3f * 1.0;
    vector<vector<double> > am; // adjacency matrix
    int n;
    void init(int number_of_nodes) {
        // reset
        vector<vector<double> >().swap(am);
        n = number_of_nodes;
        am.resize(n, vector<double>(n, INF));
        for (int i = 0; i < n; ++i) {
            am[i][i] = 0.0;
        }
    }
    void floyd_warshall() { // order: k, i, j
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (am[i][k] < INF && am[k][j] < INF) {
                        if (am[i][j] > am[i][k] + am[k][j]) {
                            am[i][j] = am[i][k] + am[k][j];
                        }
                    }
    }
    double dist(const int &u, const int &v) {
        return am[u][v];
    }
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                        time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

unordered_map<pair<int, int>, int, custom_hash> node2id;
vector<pair<int, int> > id2node;
int id;
vector<vector<int> > stations;

double dist(const pair<int, int> &l, const pair<int, int> &r, double speed) {
    return sqrt((l.first-r.first)*(l.first-r.first)+(l.second-r.second)*(l.second-r.second)) / speed;
}

void reset() {
    decltype(stations)().swap(stations);
    id = 0;
    decltype(id2node)().swap(id2node);
    node2id.clear();
}

vector<int> parse(const string &s) {
    istringstream iss(s);
    string temp;
    vector<int> result;
    do {
        iss >> temp;
        if (!temp.empty()) {
            result.emplace_back(stoi(temp));
        }
    } while (iss);
    return result;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t, x, y;
    cin >> t;
    cin.get();
    string s;
    bool first_case = true;

    while (t--) {
        reset();
        if (first_case) {
            getline(cin, s);    // empty line
        }
        cin >> x >> y;
        // home: id = 0
        node2id[{x, y}] = id;
        id2node.emplace_back(x, y);
        ++id;
        // school: id = 1
        cin >> x >> y;
        node2id[{x, y}] = id;
        id2node.emplace_back(x, y);
        ++id;
        cin.get();
        while (true) {
            if (!getline(cin, s) || s.empty()) {
                break;
            }
            auto p = parse(s);
            vector<int> vec;
            pair<int, int> temp;
            for (int i = 0; i < (int)p.size() - 1; i += 2) {
                x = p.at(i);
                y = p.at(i + 1);
                if (x == -1 && y == -1) break;
                temp.first = x;
                temp.second = y;
                if (node2id.find(temp) == node2id.end()) {
                    node2id[temp] = id;
                    id2node.emplace_back(x, y);
                    vec.emplace_back(id);
                    ++id;
                } else {
                    vec.emplace_back(node2id[temp]);
                }
            }
            stations.emplace_back(vec);
            decltype(vec)().swap(vec);
        }
        APSP::init(id);
        double d;
        int u, v;
        int n = (int)stations.size();
        for (int i = 0; i < n; ++i) {
            int m = (int)stations.at(i).size();
            for (int j = 0; j < m - 1; ++j) {
                u = stations.at(i).at(j);
                v = stations.at(i).at(j + 1);
                d = dist(id2node[u], id2node[v], SUBWAY);
                APSP::am[u][v] = d;
                APSP::am[v][u] = d;
            }
        }
        for (int i = 0; i < id; ++i) {
            for (int j = 0; j < id; ++j) {
                if (APSP::am[i][j] == APSP::INF) {
                    APSP::am[i][j] = dist(id2node[i], id2node[j], WALK);
                }
            }
        }
        APSP::floyd_warshall();
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        cout << lround(APSP::dist(0, 1)) << '\n';
    }

    return 0;
}
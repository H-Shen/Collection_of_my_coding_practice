// https://open.kattis.com/problems/hidingplaces
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 8;
constexpr int MAX_STR_LENGTH = 5;
char cstr[MAX_STR_LENGTH];

namespace SSSP {
    constexpr int MAX_NODES = 105;
    constexpr int MAX_EDGES = 10005;
    constexpr int INF = 0x3f3f3f3f;
    struct Edge {
        int to;
        int distance;
        int next;
        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };
    vector<Edge> E(MAX_EDGES);
    vector<int> head(MAX_NODES);
    int counter;
    vector<int> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    int s;

    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }
    struct Node {
        int distance;
        int position;

        explicit Node(int distance, int pos) : distance(distance), position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };
    std::priority_queue<Node> Q;
    inline void dijkstra() {
        dis.at(s) = 0;
        Q.push(Node(0, s));
        while (!Q.empty()) {
            Node tmp = Q.top();
            Q.pop();
            int x = tmp.position;
            // Base case
            if (vis.at(x)) {
                continue;
            }
            vis.at(x) = true;
            for (int i = head.at(x); i; i = E.at(i).next) {
                int y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (!vis.at(y)) {
                        Q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
    inline void reset() {
        fill(dis.begin(), dis.end(), INF);
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        Q = std::priority_queue<Node>();
    }
}

pair<int, int> conv(const string &s) {
    pair<int, int> result;
    result.first = 8 - (s.at(1) - '0');
    result.second = s.at(0) - 'a';
    return result;
}

string rev_conv(int pos) {
    string s = "xx";
    int i = pos / MAXN;
    int j = pos % MAXN;
    s.at(1) = 8 - i + '0';
    s.at(0) = j + 'a';
    return s;
}

vector<pair<int,int> > transitions = {
        {2,1},
        {2,-1},
        {-2, 1},
        {-2,-1},
        {1,2},
        {1,-2},
        {-1,2},
        {-1,-2}
};

vector<vector<bool> > vis(MAXN, vector<bool>(MAXN));
unordered_map<int, unordered_set<int> > E;

void dfs(int last, int i, int j) {
    int pos = i*MAXN+j;
    if (last != -1) {
        E[last].insert(pos);
    }
    if (vis.at(i).at(j)) {
        return;
    }
    vis.at(i).at(j) = true;
    int new_i, new_j;
    for (const auto &step : transitions) {
        new_i = i + step.first;
        new_j = j + step.second;
        if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN) {
            dfs(pos, new_i, new_j);
        }
    }
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {

        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                vis.at(i).at(j) = false;
            }
        }
        E.clear();
        SSSP::counter = 0;
        vector<SSSP::Edge>().swap(SSSP::E);
        SSSP::E.resize(SSSP::MAX_EDGES);
        vector<int>().swap(SSSP::head);
        SSSP::head.resize(SSSP::MAX_NODES);

        scanf("%s", cstr);
        string s(cstr);
        auto knight = conv(s);
        dfs(-1, knight.first, knight.second);

        // add edges
        for (const auto &[u, v_list] : E) {
            for (const auto &v : v_list) {
                SSSP::add_edge(u, v, 1);
            }
        }
        SSSP::s = knight.first * MAXN + knight.second;
        SSSP::reset();
        SSSP::dijkstra();

        // get the max distance
        int max_dist = 0;
        for (const auto &[u, v_list] : E) {
            for (const auto &v : v_list) {
                max_dist = max(max_dist, SSSP::dis.at(v));
            }
        }
        unordered_set<int> unset;
        for (const auto &[u, v_list] : E) {
            for (const auto &v : v_list) {
                if (SSSP::dis.at(v) == max_dist) {
                    unset.insert(v);
                }
            }
        }
        vector<string> output;
        for (const int &p : unset) output.emplace_back(rev_conv(p));
        sort(output.begin(), output.end(),
             [](const string &l, const string &r) {
                 auto temp0 = conv(l);
                 auto temp1 = conv(r);
                 if (temp0.first == temp1.first) {
                     return (temp0.second < temp1.second);
                 }
                 return (temp0.first < temp1.first);
             });
        printf("%d", max_dist);
        for (const string &i : output) {
            printf(" %s", i.c_str());
        }
        printf("\n");
    }

    return 0;
}

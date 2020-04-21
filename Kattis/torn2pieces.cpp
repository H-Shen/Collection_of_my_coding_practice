// https://open.kattis.com/problems/torn2pieces
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace SSSP {
    constexpr int MAX_NODES = 1005;
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
    vector<int> prev(MAX_NODES, -1);
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
    inline void dijkstra(bool store_path = false) {
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
                    if (store_path) {
                        prev.at(y) = x;
                    }
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
    vector<int> get_path(int t) {
        vector<int> path;
        for(; t!=-1; t=prev.at(t))
            path.push_back(t);
        reverse(path.begin(),path.end());
        return path;
    }
}

inline static
vector<string> splitByChar(std::string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

unordered_map<string, int> str2idx;
vector<string> idx2str;
int idx = 0;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, u, v;
    string s;
    cin >> n;
    cin.get();
    vector<string> tempVec;
    while (n--) {
        getline(cin, s);
        tempVec = splitByChar(s, ' ');
        for (const string &i : tempVec) {
            if (str2idx.find(i) == str2idx.end()) {
                str2idx[i] = idx;
                idx2str.emplace_back(i);
                ++idx;
            }
        }
        u = str2idx[tempVec.front()];
        if (tempVec.size() > 1) {
            for (size_t i = 1; i != tempVec.size(); ++i) {
                v = str2idx[tempVec.at(i)];
                SSSP::add_edge(u, v, 1);
                SSSP::add_edge(v, u, 1);
            }
        }
    }
    getline(cin, s);
    tempVec = splitByChar(s, ' ');
    int original = str2idx[tempVec.front()];
    int dest = str2idx[tempVec.back()];
    SSSP::reset();
    SSSP::s = original;
    SSSP::dijkstra(true);
    if (SSSP::dis.at(dest) == SSSP::INF || SSSP::dis.at(dest) == 0) {
        cout << "no route found\n";
    } else {
        auto path = SSSP::get_path(dest);
        bool firstItem = true;
        for (const auto &i : path) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << idx2str.at(i);
        }
        cout << '\n';
    }

    return 0;
}

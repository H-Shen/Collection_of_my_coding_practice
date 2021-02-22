#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
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


vector<pair<int, int> > edges;
vector<int> degree;
vector<deque<int> > adj;
unordered_map<int, unordered_map<int, int> > stats;


vector<int> Hierholzer(int startVertex, vector<deque<int> > &adjList) {
    stack<int> path;
    vector<int> circuit;
    int current = startVertex;
    path.push(startVertex);
    while (!path.empty()) {
        if (!adjList.at(current).empty()) {
            path.push(current);
            int next = adjList.at(current).front();
            adjList.at(current).pop_front();
            if (stats[current][next] > 0) {
                --stats[current][next];
                --stats[next][current];
                current = next;
            }
        } else {
            circuit.emplace_back(current);
            current = path.top();
            path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    return circuit;
}

int main() {

    int m;
    IO::read(m);
    edges.resize(m);
    int maxNodeID = -1;
    for (auto &i : edges) {
        IO::read(i.first, i.second);
        maxNodeID = max(maxNodeID, max(i.first, i.second));
    }
    degree.resize(maxNodeID + 1);
    adj.resize(maxNodeID + 1);
    for (const auto &i : edges) {
        ++degree[i.first];
        ++degree[i.second];
        adj[i.first].emplace_back(i.second);
        adj[i.second].emplace_back(i.first);
        ++stats[i.first][i.second];
        ++stats[i.second][i.first];
    }
    for (auto &i : adj) {
        sort(i.begin(), i.end());
    }
    vector<int> verticesWithOddDegree;
    for (int i = 1; i <= maxNodeID; ++i) {
        if (degree[i] % 2 != 0) {
            verticesWithOddDegree.emplace_back(i);
        }
    }
    int startVertex = 1;
    if (!verticesWithOddDegree.empty()) {
        startVertex = verticesWithOddDegree.front();
    }
    vector<int> vertices = Hierholzer(startVertex, adj);
    int n = (int)vertices.size();
    IO::writeln(vertices.front());
    for (int i = 1; i < n; ++i) {
        if (vertices.at(i) != vertices.at(i - 1)) {
            IO::writeln(vertices.at(i));
        }
    }
    return 0;
}
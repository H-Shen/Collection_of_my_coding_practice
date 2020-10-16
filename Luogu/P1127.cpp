#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int LETTERS = 26;

namespace DSU {
    vector<int> father;
    vector<int> Size;

    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }

    int find(int x) {
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

vector<int> Hierholzer(int start_vertex, vector<deque<int> > &adjList) {
    stack<int> path;
    vector<int> circuit;
    int current = start_vertex;
    path.push(start_vertex);
    while (!path.empty()) {
        if (!adjList.at(current).empty()) {
            path.push(current);
            int next = adjList.at(current).front();
            adjList.at(current).pop_front();
            current = next;
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

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, u, v;
    cin >> n;

    vector<deque<int> > adj(LETTERS);
    deque<string> dict[LETTERS][LETTERS]{};
    DSU::init(LETTERS);
    int in_deg[LETTERS]{};
    int out_deg[LETTERS]{};
    bitset<LETTERS> has;

    vector<string> L(n);
    for (auto &i : L) {
        cin >> i;
    }
    sort(L.begin(), L.end());
    for (const auto &i : L) {
        u = i.front() - 'a';
        v = i.back() - 'a';
        adj.at(u).emplace_back(v);
        ++in_deg[v];
        ++out_deg[u];
        DSU::merge(u, v);
        has[u] = true;
        has[v] = true;
        dict[u][v].emplace_back(i);
    }

    bitset<LETTERS + 5> ancestors;
    for (int i = 0; i < LETTERS; ++i) {
        if (has[i]) {
            ancestors[DSU::find(i)] = true;
        }
    }
    // Case 1: The CC != 1
    if (ancestors.count() != 1) {
        cout << "***" << '\n';
        return 0;
    }
    // Case 2: The CC = 1, start checking if an Eulerian cycle/path exists
    int euler_start_index = -1;
    int euler_end_index = -1;
    for (int i = 0; i < LETTERS; ++i) {
        if (!has[i]) {
            continue;
        } else if (out_deg[i] == in_deg[i]) {
            continue;
        } else if (out_deg[i] - in_deg[i] == 1) {
            if (euler_start_index != -1) {
                cout << "***" << '\n';
                return 0;
            }
            euler_start_index = i;
        } else if (in_deg[i] - out_deg[i] == 1) {
            if (euler_end_index != -1) {
                cout << "***" << '\n';
                return 0;
            }
            euler_end_index = i;
        } else {
            cout << "***" << '\n';
            return 0;
        }
    }
    // Process 2 corner cases
    if (euler_start_index != -1 && euler_end_index == -1) {
        cout << "***" << '\n';
        return 0;
    }
    if (euler_start_index == -1 && euler_end_index != -1) {
        cout << "***" << '\n';
        return 0;
    }
    // An Eulerian Cycle exists
    if (euler_start_index == -1) {
        euler_start_index = L.front().front() - 'a';
    }
    vector<int> vertices = Hierholzer(euler_start_index, adj);
    vector<string> output;
    int length = static_cast<int>(vertices.size());
    for (int i = 0; i < length - 1; ++i) {
        u = vertices.at(i);
        v = vertices.at(i + 1);
        output.emplace_back(dict[u][v].front());
        dict[u][v].pop_front();
    }
    bool first_item = true;
    for (const auto &i : output) {
        if (first_item) first_item = false;
        else cout << '.';
        cout << i;
    }
    cout << '\n';
    return 0;
}

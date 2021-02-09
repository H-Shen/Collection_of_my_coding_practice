// https://open.kattis.com/problems/bridgesandtunnels

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

namespace DSU {
    vector<int> father, Size;
    int number_of_sets;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        number_of_sets = n;
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
        --number_of_sets;
    }
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
    int check_set_size(int x) {
        return Size[find(x)];
    }
    int number_of_disjoint_sets() {
        return number_of_sets;
    }
}

unordered_map<string, int> node2id;
int id, m;
vector<pair<int, int> > edges;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> m;
    string a, b;
    int u, v;
    while (m--) {
        cin >> a;
        if (node2id.find(a) == node2id.end()) {
            node2id[a] = id;
            u = id;
            ++id;
        } else {
            u = node2id[a];
        }
        cin >> b;
        if (node2id.find(b) == node2id.end()) {
            node2id[b] = id;
            v = id;
            ++id;
        } else {
            v = node2id[b];
        }
        edges.emplace_back(u, v);
    }
    DSU::init(id);
    for (const auto &[i, j] : edges) {
        DSU::merge(i, j);
        cout << DSU::Size[DSU::find(i)] << '\n';
    }

    return 0;
}

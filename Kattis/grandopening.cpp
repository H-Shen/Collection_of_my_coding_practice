// https://open.kattis.com/problems/grandopening

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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
}

int n, m, id;
vector<int> in_degree, out_degree;
unordered_map<string, int> node2id;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    in_degree.resize(n);
    out_degree.resize(n);
    DSU::init(n);
    bool falseAlarm = true;
    string s;
    int val, u, v;
    unordered_set<int> animals_need_to_move;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        if (node2id.find(s) == node2id.end()) {
            node2id[s] = id;
            u = id;
            ++id;
        } else {
            u = node2id[s];
        }
        cin >> val;
        while (val--) {
            cin >> s;
            if (node2id.find(s) == node2id.end()) {
                node2id[s] = id;
                v = id;
                ++id;
            } else {
                v = node2id[s];
            }
            if (u != v) {
                falseAlarm = false;
                DSU::merge(u, v);
                ++out_degree.at(u);
                ++in_degree.at(v);
                animals_need_to_move.insert(u);
                animals_need_to_move.insert(v);
            }
        }
    }
    if (falseAlarm) {
        cout << "FALSE ALARM" << '\n';
        return 0;
    }
    // check if all nodes are in the same CC
    unordered_set<int> groups;
    for (const auto &i : animals_need_to_move) {
        groups.insert(DSU::find(i));
    }
    if (groups.size() != 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    int counterA = 0;
    int counterB = 0;
    for (const auto &i : animals_need_to_move) {
        if (in_degree.at(i) == out_degree.at(i)) {
            continue;
        }
        else if (in_degree.at(i) - out_degree.at(i) == 1) {
            ++counterA;
        }
        else if (out_degree.at(i) - in_degree.at(i) == 1) {
            ++counterB;
        }
        else {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    if (counterA <= 1 && counterB <= 1) {
        cout << "POSSIBLE" << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}

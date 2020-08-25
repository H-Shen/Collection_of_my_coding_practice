#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

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
    }
}

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    int kase, u, v;
    string s;
    cin >> kase;
    bool first_case = true;
    char max_node;
    while (kase--) {
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        cin >> s;
        max_node = s.at(0);
        DSU::init(max_node - 'A');
        cin.get();
        unordered_set<int> nodes;
        while (getline(cin, s)) {
            if (s.empty()) break;
            u = s.at(0) - 'A';
            v = s.at(1) - 'A';
            DSU::merge(u, v);
        }
        unordered_set<int> groups;
        for (char ch = 'A'; ch <= max_node; ++ch) {
            groups.insert(DSU::find(ch - 'A'));
        }
        cout << groups.size() << '\n';
    }
    return 0;
}
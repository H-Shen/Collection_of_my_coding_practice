// https://open.kattis.com/problems/skolavslutningen

#include <bits/extc++.h>

using namespace std;

int n, m, k;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
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
        x = find(x), y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    DSU::init(n * m);
    vector<vector<char> > A;
    string s;
    unordered_map<char, vector<int> > classes;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        A.emplace_back(s.begin(), s.end());
        for (size_t j = 0; j != s.size(); ++j) {
            classes[s[j]].emplace_back(i * m + j);
        }
    }
    for (const auto &[k, vList] : classes) {
        if (vList.size() > 1) {
            for (size_t i = 0; i != vList.size() - 1; ++i) {
                DSU::merge(vList.at(i), vList.at(i + 1));
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            // A[j][i], A[j + 1][i]
            DSU::merge(j * m + i, (j + 1) * m + i);
        }
    }
    unordered_map<int, int> groups;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ++groups[DSU::find(i * m + j)];
        }
    }
    cout << groups.size() << '\n';

    return 0;
}

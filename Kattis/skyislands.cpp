// https://open.kattis.com/problems/skyislands

#include <bits/stdc++.h>

using namespace std;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5,1);
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
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, u, v;
    cin >> n >> m;
    DSU::init(n);
    while (m--) {
        cin >> u >> v;
        DSU::merge(u, v);
    }
    if (DSU::Size[DSU::find(1)] == n) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';
    return 0;
}

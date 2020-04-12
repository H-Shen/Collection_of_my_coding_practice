#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

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
        x = find(x), y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

unordered_map<string, int> unmap;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    string name;
    cin >> n >> m;
    DSU::init(n);
    for (int i = 0; i < n; ++i) {
        cin >> name;
        unmap[name] = i;
    }
    string a, b;
    while (m--) {
        cin >> a >> b;
        DSU::merge(unmap[a], unmap[b]);
    }
    int k;
    cin >> k;
    while (k--) {
        cin >> a >> b;
        if (unmap.find(a) == unmap.end() || unmap.find(b) == unmap.end()) {
            cout << "No." << '\n';
        }
        else if (!DSU::is_same_group(unmap[a], unmap[b])) {
            cout << "No." << '\n';
        }
        else {
            cout << "Yes." << '\n';
        }
    }
    
    return 0;
}

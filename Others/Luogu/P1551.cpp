#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    inline static
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    inline static
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    inline static
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
    inline static
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}


int main() {

    int n, m, p, x, y;
    scanf("%d %d %d", &n, &m, &p);
    DSU::init(n);
    while (m--) {
        scanf("%d %d", &x, &y);
        DSU::merge(x, y);
    }
    while (p--) {
        scanf("%d %d", &x, &y);
        printf(DSU::is_same_group(x, y) ? "Yes\n" : "No\n");
    }
    return 0;
}

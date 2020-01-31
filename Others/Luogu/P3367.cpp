#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace DSU {
    vector<int> Size;
    vector<int> father;
    void make_set(int n) {
        Size.resize(n, 1);
        father.resize(n);
        iota(father.begin(), father.end(), 0);
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
        father[x] = y;
        Size[y] += Size[x];
    }
    bool same_set(int i, int j) {
        return find(i) == find(j);
    }
}

int main() {

    int n, m;
    int z, x, y;
    scanf("%d %d", &n, &m);
    DSU::make_set(n + 1);
    while (m--) {
        scanf("%d %d %d", &z, &x, &y);
        if (z == 1) {
            DSU::merge(x, y);
        } else {
            if (DSU::same_set(x, y)) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
        }
    }
    
    return 0;
}
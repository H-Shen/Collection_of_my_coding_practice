// https://open.kattis.com/problems/reachableroads
//
#include <bits/extc++.h>

using namespace std;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n, 1);
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

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        int m;
        scanf("%d", &m);
        DSU::init(m);
        int r, x, y;
        scanf("%d", &r);
        while (r--) {
            scanf("%d %d", &x, &y);
            DSU::merge(x, y);
        }
        unordered_set<int> uniq_city;
        for (int i = 0; i < m; ++i) {
            uniq_city.insert(DSU::find(i));
        }
        printf("%lu\n", uniq_city.size() - 1);
    }

    return 0;
}

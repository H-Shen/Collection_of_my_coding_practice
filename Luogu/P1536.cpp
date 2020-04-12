#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 1005;

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
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

int main() {

    int n, m, x, y;
    while (~scanf("%d", &n) && n != 0) {
        DSU::init(MAXN);
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &x, &y);
            DSU::merge(x, y);
        }
        unordered_set<int> groups;
        for (int i = 1; i <= n; ++i) {
            groups.insert(DSU::find(i));
        }
        printf("%d\n", static_cast<int>(groups.size() - 1));
    }
    return 0;
}

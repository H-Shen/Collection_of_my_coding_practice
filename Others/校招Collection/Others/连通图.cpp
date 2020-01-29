// https://www.nowcoder.com/practice/569e89823a5141fe8a11ab7d4da21edf

#include <bits/stdc++.h>

using namespace std;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void make_set(int n) {
        // clear
        vector<int>().swap(father);
        vector<int>().swap(Size);
        // initialization
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 0);
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

    int n, m, x, y;
    while (~scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }
        DSU::make_set(n);
        while (m--) {
            scanf("%d %d", &x, &y);
            DSU::merge(x, y);
        }
        unordered_set<int> groups;
        for (int i = 1; i <= n; ++i) {
            groups.insert(DSU::find(i));
        }
        if (groups.size() == 1) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}

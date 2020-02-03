// https://open.kattis.com/problems/tildes
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 5;
char op[MAXN];

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void make_set(int n) {
        father.resize(n);
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

    int n, q;
    scanf("%d %d", &n, &q);
    DSU::make_set(n + 5);
    int x, y;
    while (q--) {
        scanf("%s", op);
        if (strcmp(op, "t") == 0) {
            scanf("%d %d", &x, &y);
            DSU::merge(x, y);
        } else {
            scanf("%d", &x);
            printf("%d\n", DSU::Size[DSU::find(x)]);
        }
    }

    return 0;
}

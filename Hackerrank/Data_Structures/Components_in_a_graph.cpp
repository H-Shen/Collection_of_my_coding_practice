#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void make_set(int n) {
        father.resize(n);
        iota(father.begin(), father.end(), 0);
        Size.resize(n, 1);
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
}


int main() {

    int n, x, y;
    scanf("%d", &n);
    DSU::make_set(2 * n + 5);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        DSU::merge(x, y);
    }
    unordered_map<int, unordered_set<int> > stats;
    for (int i = 1; i <= 2 * n; ++i) {
        stats[DSU::find(i)].insert(i);
    }
    int min_val = numeric_limits<int>::max();
    int max_val = numeric_limits<int>::min();
    int temp;
    for (const auto &i : stats) {
        temp = static_cast<int>(i.second.size());
        if (temp > 1) {
            min_val = min(min_val, temp);
            max_val = max(max_val, temp);
        }
    }
    printf("%d %d\n", min_val, max_val);

    return 0;
}
// https://www.nowcoder.com/practice/7c29cdfa28274c86afc9e88c07448a10

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 1000000;

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
    DSU::init(MAXN);
    unordered_set<int> nodes;
    int i, j;
    while (~scanf("%d %d", &i, &j)) {
        DSU::merge(i, j);
        nodes.insert(i);
        nodes.insert(j);
    }
    unordered_set<int> groups;
    for (const auto &i : nodes) {
        groups.insert(DSU::find(i));
    }
    printf("%zd\n", groups.size());
    return 0;
}
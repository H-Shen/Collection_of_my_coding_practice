// https://www.nowcoder.com/practice/1fe6c3136d2a45fa8ef555b459b6dd26

#include <bits/stdc++.h>

using namespace std;

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
    
    int n;
    scanf("%d", &n);
    DSU::init(n);
    int ai;
    scanf("%d", &ai);
    int m;
    scanf("%d", &m);
    int x, y;
    int peopleThatAlreadyKnow = 0;
    while (m--) {
        scanf("%d,%d", &x, &y);
        DSU::merge(x, y);
        if (x == ai || y == ai) {
            ++peopleThatAlreadyKnow;
        }
    }
    printf("%d\n", DSU::Size[DSU::find(ai)] - 1 - peopleThatAlreadyKnow);

    return 0;
}
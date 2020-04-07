#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 20500;

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
}

unordered_map<int, int> id2pos;
unordered_map<int, int> pos2id;
unordered_set<int> groups;
int counter = 0;

int main() {

    int n, m, p, q, a, b;
    scanf("%d %d %d %d", &n, &m, &p, &q);
    DSU::init(MAXN);
    id2pos[-1] = counter;
    pos2id[counter] = -1;
    ++counter;
    id2pos[1] = counter;
    pos2id[counter] = 1;
    ++counter;
    DSU::merge(id2pos[-1], id2pos[1]);
    for (int i = 0; i < p; ++i) {
        scanf("%d %d", &a, &b);
        if (id2pos.find(a) == id2pos.end()) {
            id2pos[a] = counter;
            pos2id[counter] = a;
            ++counter;
        }
        if (id2pos.find(b) == id2pos.end()) {
            id2pos[b] = counter;
            pos2id[counter] = b;
            ++counter;
        }
        DSU::merge(id2pos[a], id2pos[b]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d %d", &a, &b);
        if (id2pos.find(a) == id2pos.end()) {
            id2pos[a] = counter;
            pos2id[counter] = a;
            ++counter;
        }
        if (id2pos.find(b) == id2pos.end()) {
            id2pos[b] = counter;
            pos2id[counter] = b;
            ++counter;
        }
        DSU::merge(id2pos[a], id2pos[b]);
    }
    int group_id = DSU::find(id2pos[1]);
    for (int i = 0; i < counter; ++i) {
        if (DSU::find(i) == group_id) {
            groups.insert(pos2id[i]);
        }
    }
    int negative = 0;
    int positive = 0;
    for (const auto &i : groups) {
        if (i < 0) {
            ++negative;
        } else {
            ++positive;
        }
    }
    printf("%d\n", min(negative, positive));
    
    return 0;
}
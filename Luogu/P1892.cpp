#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 5;
char s[MAXN];

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
        x = find(x), y = find(y);
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

unordered_map<int, unordered_set<int> > E;
unordered_set<int> groups;

int main() {

    int n;
    scanf("%d", &n);
    DSU::init(n);
    int m, a, b;
    scanf("%d", &m);
    while (m--) {
        scanf("%s %d %d", s, &a, &b);
        if (strcmp(s, "F") == 0) {
            DSU::merge(a, b);
        } else {
            E[a].insert(b);
            E[b].insert(a);
        }
    }
    bool first_item;
    for (const auto &[k, v_list] : E) {
        if (v_list.size() > 1) {
            first_item = true;
            int current_v = -1;
            for (const auto &v_element : v_list) {
                if (first_item) {
                    first_item = false;
                    current_v = v_element;
                } else {
                    DSU::merge(current_v, v_element);
                    current_v = v_element;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        groups.insert(DSU::find(i));
    }
    printf("%zd\n", groups.size());

    return 0;
}
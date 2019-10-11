// https://open.kattis.com/problems/almostunionfind
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int maxn = 200005;

ll sum[maxn]; // An array where sum[i] is the sum of all elements in set i
int father[maxn]; // Father nodes
int id[maxn];
int Size[maxn]; // An array where Size[i] is the size of set i
int n;

int find(int x) {
    if (x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void merge(int x, int y) {

    int the_set_includes_x = find(id[x]);
    int the_set_includes_y = find(id[y]);
    father[the_set_includes_x] = the_set_includes_y;
    sum[the_set_includes_y] += sum[the_set_includes_x];
    Size[the_set_includes_y] += Size[the_set_includes_x];
}

void split(int x) {
    int the_set_includes_x = find(id[x]);
    --Size[the_set_includes_x];
    sum[the_set_includes_x] -= static_cast<ll>(x);
    id[x] = ++n;
    father[id[x]] = id[x];
    Size[id[x]] = 1;
    sum[id[x]] = static_cast<ll>(x);
}

void reset() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        id[i] = i;
        sum[i] = static_cast<ll>(i);
        Size[i] = 1;
    }
}

int main() {

    int m;
    int op, p, q, temp;
    while (~scanf("%d %d", &n, &m)) {
        reset();
        while (m--) {
            scanf("%d", &op);
            switch (op) {
                // 1 p q
                case 1:
                    scanf("%d %d", &p, &q);
                    if (find(id[p]) != find(id[q])) {
                        merge(p, q);
                    }
                    break;
                    // 2 p q
                case 2:
                    scanf("%d %d", &p, &q);
                    if (find(id[p]) != find(id[q])) {
                        split(p);
                        merge(p, q);
                    }
                    break;
                    // 3 p
                default:
                    scanf("%d", &p);
                    temp = find(id[p]);
                    printf("%d %lld\n", Size[temp], sum[temp]);
                    break;
            }
        }
    }
    return 0;
}

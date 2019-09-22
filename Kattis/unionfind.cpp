// https://open.kattis.com/problems/unionfind
//
#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 1000005;

int father[maxn]; // Father nodes
int Rank[maxn]; // Rank

int find(int x) {
    if (x != father[x])
        father[x] = find(father[x]);
    return father[x];
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);

    if (Rank[x] > Rank[y]) {
        father[y] = x;
    } else {
        father[x] = y;
        if (Rank[x] == Rank[y])
            Rank[y] += 1;
    }
}

void reset(int n) {
    for (int i = 0; i <= n; i++) {
        father[i] = i;
        Rank[i] = 0;
    }
}

int main() {

    int N, Q, a, b;
    char op;
    scanf("%d %d", &N, &Q);
    reset(N);
    getchar();

    for (int i = 0; i < Q; ++i) {
        scanf("%c %d %d", &op, &a, &b);
        getchar();
        if (op == '?') {
            if (find(a) == find(b)) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        } else {
            merge(a, b);
        }
    }


    return 0;
}

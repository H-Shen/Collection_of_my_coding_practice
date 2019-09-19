// https://open.kattis.com/problems/moneymatters
//
#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 100005;

int node[maxn];
int visit[maxn];

int find(int x){
    if (x == node[x]) { return x; } return find(node[x]);
}

void merge(int x,int y) {
    x = find(x); y = find(y); if (x == y) { return; }
    node[x] = y;
}

void init(int n) {
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i < n + 1; ++i) {
        node[i] = i;
    }
}


unordered_map<int, int> moneySum;
int moneyList[10005];

int main() {


    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &moneyList[i]);
    }

    init(n);

    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        merge(a, b);
    }

    for (int i = 0; i < n; ++i) {
        moneySum[find(i)] += moneyList[i];
    }

    bool canGetEven = true;
    for (const auto &it : moneySum) {
        if (it.second < 0) {
            canGetEven = false;
            break;
        }
    }
    if (canGetEven) {
        printf("POSSIBLE\n");
    } else {
        printf("IMPOSSIBLE\n");
    }


    return 0;
}

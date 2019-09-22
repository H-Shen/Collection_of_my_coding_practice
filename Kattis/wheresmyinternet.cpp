// https://open.kattis.com/problems/wheresmyinternet
//
#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 200005;

int father[maxn]; // Father nodes
int Rank[maxn]; // Rank

int result[maxn];
int result_length = 0;

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

void reset() {
    for (int i = 1; i < maxn; i++) {
        father[i] = i;
        Rank[i] = 0;
    }
}

int main() {

    reset();

    int N, M, a, b;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &a, &b);
        merge(a, b);
    }
    int groupNumber = find(1);
    for (int i = 2; i <= N; ++i) {
        if (find(i) != groupNumber) {
            result[result_length++] = i;
        }
    }
    if (result_length == 0) {
        printf("Connected\n");
    } else {
        sort(result, result + result_length);
        for (int i = 0; i < result_length; ++i) {
            printf("%d\n", result[i]);
        }
    }

    return 0;
}

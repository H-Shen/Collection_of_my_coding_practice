#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;

struct Stu {
    char name[MAXN], id[MAXN];
    int score;
};

bool cmp(const Stu &a, const Stu &b) {
    return (a.score > b.score);
}

int main() {
    int n, i;
    scanf("%d", &n);
    vector<Stu> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%s %s %d", A[i].name, A[i].id, &A[i].score);
    }
    auto res = minmax_element(A.begin(), A.end(), cmp);
    printf("%s %s\n", res.first->name, res.first->id);
    printf("%s %s\n", res.second->name, res.second->id);
    return 0;
}
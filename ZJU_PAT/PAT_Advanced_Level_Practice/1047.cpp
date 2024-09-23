#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10;
char s[MAXN];

int main() {
    int n, k, i, j, m, courseNum;
    string name;
    scanf("%d %d", &n, &k);
    vector<vector<string> > A(k + 5);
    for (i = 0; i < n; ++i) {
        scanf("%s %d", s, &m);
        name = s;
        for (j = 0; j < m; ++j) {
            scanf("%d", &courseNum);
            A[courseNum].push_back(name);
        }
    }

    for (i = 1; i <= k; ++i) {
        printf("%d %d\n", i, static_cast<int>(A[i].size()));
        sort(A[i].begin(), A[i].end());
        for (auto it = A[i].cbegin(); it != A[i].cend(); ++it) {
            printf("%s\n", (*it).c_str());
        }
    }
    return 0;
}
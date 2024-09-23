#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > A;

int main() {
    int n;
    scanf("%d", &n);
    int i, cnt, j, tmp;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &cnt);
        unordered_set<int> a;
        for (j = 0; j < cnt; ++j) {
            scanf("%d", &tmp);
            a.insert(tmp);
        }
        vector<int> a_vec(a.begin(), a.end());
        sort(a_vec.begin(), a_vec.end());
        A[i] = a_vec;
    }
    int m, seta, setb;
    scanf("%d", &m);
    for (i = 1; i <= m; ++i) {
        scanf("%d %d", &seta, &setb);
        vector<int> C, T;
        set_intersection(A[seta].begin(), A[seta].end(), A[setb].begin(), A[setb].end(), back_inserter(C));
        set_union(A[seta].begin(), A[seta].end(), A[setb].begin(), A[setb].end(), back_inserter(T));
        printf("%.1lf%%\n", (double) C.size() / (double) T.size() * 100.0);
    }

    return 0;
}
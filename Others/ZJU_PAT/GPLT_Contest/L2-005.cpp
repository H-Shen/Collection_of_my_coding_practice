#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > A;

double scale(vector<int> &A, vector<int> &B) {
    vector<int> arrayUnion;
    vector<int> arrayIntersection;
    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(arrayUnion));
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(arrayIntersection));
    return (double) arrayIntersection.size() / (double) arrayUnion.size() * 100.0;
}

int main() {
    int n, i, m, tmp;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> m;
        unordered_set<int> tmpSet;
        while (m--) {
            cin >> tmp;
            tmpSet.insert(tmp);
        }
        copy(tmpSet.begin(), tmpSet.end(), back_inserter(A[i]));
        sort(A[i].begin(), A[i].end());
    }
    int query, querySetA, querySetB;
    cin >> query;
    while (query--) {
        cin >> querySetA >> querySetB;
        printf("%.2f%%\n", scale(A[querySetA], A[querySetB]));
    }
    return 0;
}

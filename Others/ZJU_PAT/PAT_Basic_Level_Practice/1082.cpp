#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct shooter {
    string id;
    int x, y, d;
};

bool cmp(const shooter &a, const shooter &b) {
    return (a.d < b.d);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, i;
    cin >> n;
    vector<shooter> A(static_cast<size_t>(n));
    for (i = 0; i < n; ++i) {
        cin >> A[i].id >> A[i].x >> A[i].y;
        A[i].x = abs(A[i].x);
        A[i].y = abs(A[i].y);
        A[i].d = A[i].x * A[i].x + A[i].y * A[i].y;
    }
    sort(A.begin(), A.end(), cmp);
    cout << A.front().id << ' ' << A.back().id << endl;
    return 0;
}
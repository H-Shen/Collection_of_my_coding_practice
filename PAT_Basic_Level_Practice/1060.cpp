#include <bits/stdc++.h>

using namespace std;

bool cmp(const int &a, const int &b) {
    return (a > b);
}

int main() {

    int n, i;
    scanf("%d", &n);
    vector<int> A(static_cast<size_t>(n + 1));

    for (i = 1; i <= n; ++i) cin >> A[i];

    sort(A.begin() + 1, A.end(), cmp);

    int E = 0;
    i = 1;
    while (E <= n && A[i] > i) {
        ++E;
        ++i;
    }
    cout << E << endl;

    return 0;
}
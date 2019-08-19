#include <bits/stdc++.h>

using namespace std;

void change(string &s) {
    if (s.size() != 3) {
        s = string(3 - s.size(), '0') + s;
    }
}

int main() {
    int n, m, a, b, val, tmp;
    scanf("%d %d %d %d %d", &m, &n, &a, &b, &val);
    string tmpStr = to_string(val);
    change(tmpStr);
    int i, j;

    vector<vector<string> > A(static_cast<size_t>(m));
    for (i = 0; i < m; ++i) {
        A[i].resize(static_cast<size_t>(n));
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &tmp);
            if (tmp >= a && tmp <= b) {
                A[i][j] = tmpStr;
            } else {
                A[i][j] = to_string(tmp);
                change(A[i][j]);
            }
        }
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n - 1; ++j) {
            printf("%s ", A[i][j].c_str());
        }
        printf("%s\n", A[i][n - 1].c_str());
    }
    return 0;
}
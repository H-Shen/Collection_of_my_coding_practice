#include <bits/stdc++.h>

using namespace std;

const int maxDiff = 10000;

int main() {
    string s;
    cin >> s;
    int n1, n2, N;
    N = s.size();
    int diff = maxDiff;
    int n1_ans = -1;
    int n2_ans = -1;

    for (n2 = 3; n2 >= 3 && n2 <= N; ++n2) {
        if ((N + 2 - n2) % 2 == 0) {
            n1 = (N + 2 - n2) / 2;
            if (n1 <= n2 && diff >= abs(n1 - n2)) {
                n1_ans = n1;
                n2_ans = n2;
                diff = abs(n1 - n2);
            }
        }
    }

    vector<vector<char> > A(n1_ans, vector<char>(n2_ans));

    for (int i = 0; i < n1_ans; ++i) {
        for (int j = 0; j < n2_ans; ++j) {
            A[i][j] = ' ';
        }
    }

    int pos = 0;
    for (int i = 0; i < n1_ans; ++i) {
        A[i][0] = s[pos];
        ++pos;
    }
    for (int i = 1; i < n2_ans; ++i) {
        A[n1_ans - 1][i] = s[pos];
        ++pos;
    }
    for (int i = n1_ans - 2; i >= 0; --i) {
        A[i][n2_ans - 1] = s[pos];
        ++pos;
    }

    for (int i = 0; i < n1_ans; ++i) {
        for (int j = 0; j < n2_ans; ++j) {
            cout << A[i][j];
        }
        cout << endl;
    }
    return 0;
}

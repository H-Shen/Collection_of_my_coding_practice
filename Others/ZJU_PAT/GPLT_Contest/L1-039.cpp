#include <bits/stdc++.h>

using namespace std;

int main() {

    int B, W;
    cin >> B;
    getchar();
    string s;
    getline(cin, s);

    int len = s.size();
    int rest = len % B;
    if (rest != 0) {
        W = len / B + 1;
    } else {
        W = len / B;
    }

    if (B == 1) {
        reverse(s.begin(), s.end());
        cout << s << endl;
        return 0;
    }

    vector<vector<char> > A(W);
    int i, j;
    for (i = 0; i < W; ++i) {
        A[i].resize(B);
    }
    int pos = 0;
    for (i = 0; i < W; ++i) {
        for (j = 0; j < B; ++j) {
            if (pos == len) {
                A[i][j] = ' ';
            } else {
                A[i][j] = s[pos];
                ++pos;
            }
        }
    }

    for (i = 0; i < B; ++i) {
        string tmp;
        for (j = 0; j < W; ++j) {
            tmp = tmp + A[j][i];
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp << endl;
    }
    return 0;
}
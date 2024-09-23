#include <bits/stdc++.h>

using namespace std;

int main() {

    int m, s;
    cin >> m >> s;
    vector<vector<int> > A(m, vector<int>(s));

    int i, j, k;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < s; ++j) {
            cin >> A.at(i).at(j);
        }
    }

    int s0, n;
    cin >> s0 >> n;

    if (s0 != s) {
        cout << "Error: " << s << " != " << s0 << endl;
        return 0;
    }

    vector<vector<int> > B(s, vector<int>(n));
    for (i = 0; i < s; ++i) {
        for (j = 0; j < n; ++j) {
            cin >> B.at(i).at(j);
        }
    }

    vector<vector<int> > C(m, vector<int>(n));
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            for (k = 0; k < s; ++k) {
                C.at(i).at(j) = C.at(i).at(j) + A.at(i).at(k) * B.at(k).at(j);
            }
        }
    }

    cout << m << ' ' << n << endl;
    for (i = 0; i < m; ++i) {
        for (j = 0; j < n - 1; ++j) {
            cout << C.at(i).at(j) << ' ';
        }
        cout << C.at(i).at(n - 1) << endl;
    }

    return 0;
}
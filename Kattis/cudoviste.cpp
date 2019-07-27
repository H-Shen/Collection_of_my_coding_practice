// https://open.kattis.com/problems/cudoviste
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    size_t r, c;
    string s, tmp;
    cin >> r >> c;
    vector<vector<char> > A(r, vector<char>(c));

    for (size_t i = 0; i < r; ++i) {
        cin >> s;
        for (size_t j = 0; j < r; ++j) {
            A[i][j] = s[j];
        }
    }

    int a = 0, b = 0, C = 0, d = 0, e = 0;
    int cnt = 0;
    for (size_t i = 0; i < r; ++i) {
        for (size_t j = 0; j < c; ++j) {
            tmp = "";
            try {
                tmp = A.at(i).at(j) + string("") + A.at(i).at(j + 1) +
                      string("") + A.at(i + 1).at(j) + string("") + A.at(i + 1).at(j + 1);
            } catch (...) { continue; }

            cnt = 0;
            if (find(tmp.begin(), tmp.end(), '#') == tmp.end()) {
                for (const auto &k : tmp) {
                    if (k == 'X') {
                        ++cnt;
                    }
                }
                if (cnt == 4) ++e;
                if (cnt == 3) ++d;
                if (cnt == 2) ++C;
                if (cnt == 1) ++b;
                if (cnt == 0) ++a;
            }
        }
    }

    cout << a << endl;
    cout << b << endl;
    cout << C << endl;
    cout << d << endl;
    cout << e << endl;

    return 0;
}

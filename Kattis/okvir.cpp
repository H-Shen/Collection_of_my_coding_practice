// https://open.kattis.com/problems/okvir
//
#include <bits/extc++.h>

using namespace std;

int main() {

    size_t m, n, u, l, r, d;
    cin >> m >> n;
    cin.get();
    cin >> u >> l >> r >> d;
    cin.get();

    vector<vector<char> > A(m + u + d, vector<char>(n + l + r));
    for (size_t i = u; i != u + m; ++i) {
        for (size_t j = l; j != l + n; ++j) {
            cin >> A.at(i).at(j);
        }
        cin.get();
    }

    vector<vector<char> > B(m + u + d, vector<char>(n + l + r));
    for (size_t i = 0; i != B.size(); ++i) {
        for (size_t j = 0; j != B.at(i).size(); ++j) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    B.at(i).at(j) = '#';
                } else {
                    B.at(i).at(j) = '.';
                }
            } else {
                if (j % 2 == 0) {
                    B.at(i).at(j) = '.';
                } else {
                    B.at(i).at(j) = '#';
                }
            }
        }
    }

    for (size_t i = 0; i != B.size(); ++i) {
        for (size_t j = 0; j != B.at(i).size(); ++j) {
            if (!isalpha(A.at(i).at(j))) {
                A.at(i).at(j) = B.at(i).at(j);
            }
        }
    }

    // output
    for (const auto &i : A) {
        for (const auto &j : i) {
            cout << j;
        }
        cout << endl;
    }


    return 0;
}

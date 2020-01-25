// https://open.kattis.com/problems/coast
//
#include <bits/extc++.h>

using namespace std;

vector<vector<char> > A;

void go(int i, int j) {
    try {
        if (A.at(i).at(j) == '0') {
            A.at(i).at(j) = '2';
            go(i - 1, j);
            go(i + 1, j);
            go(i, j - 1);
            go(i, j + 1);
        }
    } catch (...) {}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, idx;
    string s;
    cin >> n >> m;
    A.resize(n + 2);
    for (auto &i : A) {
        i.resize(m + 2);
    }
    for (int i = 0; i < n + 2; ++i) {
        if (i > 0 && i < n + 1) {
            cin >> s;
        }
        idx = 0;
        for (int j = 0; j < m + 2; ++j) {
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1) {
                A.at(i).at(j) = '0';
            } else {
                A.at(i).at(j) = s.at(idx);
                ++idx;
            }
        }
    }

    // scan and mark
    go(0, 0);

    // scan and calculate
    int counter = 0;
    for (int i = 0; i < n + 2; ++i) {
        for (int j = 0; j < m + 2; ++j) {
            if (A.at(i).at(j) == '1') {
                if (A.at(i + 1).at(j) == '2') {
                    ++counter;
                }
                if (A.at(i - 1).at(j) == '2') {
                    ++counter;
                }
                if (A.at(i).at(j - 1) == '2') {
                    ++counter;
                }
                if (A.at(i).at(j + 1) == '2') {
                    ++counter;
                }
            }
        }
    }

    cout << counter << '\n';
    return 0;
}

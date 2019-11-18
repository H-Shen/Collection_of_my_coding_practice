// https://open.kattis.com/problems/thisaintyourgrandpascheckerboard
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    size_t n;
    cin >> n;
    cin.get();
    vector<vector<char> > A(n, vector<char>(n));
    for (auto &i : A) {
        for (auto &j : i) {
            cin >> j;
        }
        cin.get();
    }

    int black;
    int white;
    // row
    for (const auto &i : A) {
        black = 0;
        white = 0;
        for (const auto &j : i) {
            if (j == 'B') {
                ++black;
            } else {
                ++white;
            }
        }
        if (black != white) {
            cout << 0 << endl;
            return 0;
        }
    }

    // col
    for (size_t i = 0; i != n; ++i) {
        black = 0;
        white = 0;
        for (size_t j = 0; j != n; ++j) {
            if (A.at(j).at(i) == 'B') {
                ++black;
            } else {
                ++white;
            }
        }
        if (black != white) {
            cout << 0 << endl;
            return 0;
        }
    }

    // 3 or more consecutive
    for (const auto &i : A) {
        string temp;
        for (const auto &j : i) {
            temp.push_back(j);
        }
        if (temp.find("BBB") != string::npos || temp.find("WWW") != string::npos) {
            cout << 0 << endl;
            return 0;
        }
    }
    for (size_t i = 0; i != n; ++i) {
        string temp;
        for (size_t j = 0; j != n; ++j) {
            temp.push_back(A.at(j).at(i));
        }
        if (temp.find("BBB") != string::npos || temp.find("WWW") != string::npos) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << 1 << endl;

    return 0;
}

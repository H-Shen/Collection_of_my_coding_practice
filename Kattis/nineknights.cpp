// https://open.kattis.com/problems/nineknights
#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const int MAXN = 5;

inline
int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

bool judge(const vector<vector<char> > &A, int i, int j) {
    char s = '\0';
    try {
        s = A.at(i - 2).at(j - 1);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i - 1).at(j - 2);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i + 1).at(j - 2);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i + 2).at(j - 1);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i - 2).at(j + 1);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i - 1).at(j + 2);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i + 1).at(j + 2);
        if (s == 'k') return false;
    }
    catch (...) {}
    try {
        s = A.at(i + 2).at(j + 1);
        if (s == 'k') return false;
    }
    catch (...) {}

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    vector<vector<char> > A(MAXN);
    for (auto &&i : A) {
        i.resize(MAXN);
    }

    string s;
    for (int i = 0; i < MAXN; ++i) {
        cin >> s;
        for (int j = 0; j < MAXN; ++j) {
            A[i][j] = s[j];
        }
    }

    int knightCnt = 0;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            if (A[i][j] == 'k') {
                ++knightCnt;
                if (!judge(A, i, j)) {
                    cout << "invalid" << endl;
                    return 0;
                }
            }
        }
    }

    if (knightCnt != 9) {
        cout << "invalid" << endl;
    } else {
        cout << "valid" << endl;
    }

    return 0;
}

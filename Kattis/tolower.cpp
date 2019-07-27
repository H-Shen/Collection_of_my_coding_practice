// https://open.kattis.com/problems/tolower

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int p, t;
    string s;
    bool solve = true;
    int solveCnt = 0;

    cin >> p >> t;
    for (int i = 0; i < p; ++i) {
        solve = true;
        for (int j = 0; j < t; ++j) {
            cin >> s;
            if (solve && s.size() > 1) {
                for (size_t k = 1; k < s.size(); ++k) {
                    if (isupper(s[k])) {
                        solve = false;
                        break;
                    }
                }
            }
        }
        if (solve) {
            ++solveCnt;
        }
    }
    cout << solveCnt << endl;
    return 0;
}

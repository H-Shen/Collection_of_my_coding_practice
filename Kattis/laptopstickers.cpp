// https://open.kattis.com/problems/laptopstickers

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

int main() {
    int h,l,n;
    cin >> l >> h >> n;
    vector<vector<char>> A(h, vector<char>(l, '_'));
    int h_,l_,r,c;
    char ch = 'a';
    for (int i = 0; i < n; ++i, ++ch) {
        cin >> l_ >> h_ >> c >> r;
        for (int j = r, k = 0; k < h_; ++j, ++k) {
            for (int p = c, q = 0; q < l_; ++p, ++q) {
                if (j >= 0 && j < h && p >= 0 && p < l) A[j][p] = ch;
            }
        }
    }
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < l; ++j) {
            cout << A[i][j];
        }
        cout << '\n';
    }
    return 0;
}

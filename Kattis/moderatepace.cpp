// https://open.kattis.com/problems/moderatepace
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(3));
    for (int j = 0; j < 3; ++j) {
        for (int i = 0; i < n; ++i) {
            cin >> A[i][j];
        }
    }
    for (auto&i : A) {
        sort(i.begin(),i.end());
        cout << i[1] << ' ';
    }
    cout << '\n';
    return 0;
}

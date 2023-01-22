// https://open.kattis.com/problems/bishops
//
#include <bits/stdc++.h>

using namespace std;

inline
int solve(int n) {
    if (n <= 1) {
        return n;
    }
    return 2*(n-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n) {
        cout << solve(n) << '\n';
    }
    return 0;
}

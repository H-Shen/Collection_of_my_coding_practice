// https://open.kattis.com/problems/judgingmoose
#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int l, r, maxVal;
    cin >> l >> r;
    if (l == 0 && r == 0) {
        cout << "Not a moose" << endl;
    } else if (l != r) {
        maxVal = max(l, r) * 2;
        cout << "Odd " << maxVal << endl;
    } else {
        cout << "Even " << l * 2 << endl;
    }
    return 0;
}

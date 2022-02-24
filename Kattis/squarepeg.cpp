// https://open.kattis.com/problems/squarepeg

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int l, r;
    cin >> l >> r;
    if (l*l <= 2*r*r) {
        cout << "fits" << '\n';
    }
    else {
        cout << "nope" << '\n';
    }
    return 0;
}

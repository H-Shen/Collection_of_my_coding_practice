#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {

    int n, t;
    cin >> n >> t;
    if (t < 10) {
        cout << string(n, '0' + t) << '\n';
    } else {
        if (n == 1) {
            cout << -1 << '\n';
        } else {
            cout << 1 << string(n - 1, '0') << '\n';
        }
    }


    return 0;
}
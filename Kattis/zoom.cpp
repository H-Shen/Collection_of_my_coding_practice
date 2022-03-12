// https://open.kattis.com/problems/zoom

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

int n,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    cin >> n >> k;
    int val;
    bool firstItem = true;
    for (int i = 0, j = 1; i < n; ++i, ++j) {
        cin >> val;
        if (j % k == 0) {
            if (firstItem) {
                firstItem = false;
            } else {
                cout << ' ';
            }
            cout << val;
        }
    }
    cout << '\n';
    return 0;
}

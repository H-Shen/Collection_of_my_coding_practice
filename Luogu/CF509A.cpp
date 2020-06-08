#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    cin >> n;
    vector<vector<int> > a(n + 1, vector<int>(n + 1));
    for (int k = 1; k <= n; ++k) {
        a[k][1] = 1;
        a[1][k] = 1;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    int max_element = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            max_element = max(max_element, a[i][j]);
        }
    }
    cout << max_element << '\n';

    return 0;
}
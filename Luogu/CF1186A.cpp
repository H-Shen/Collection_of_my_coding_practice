#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, m, k;
    cin >> n >> m >> k;
    if (m >= n && k >= n) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }

    return 0;
}

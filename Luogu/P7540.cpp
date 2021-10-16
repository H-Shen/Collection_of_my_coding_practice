#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    int n;
    int sum = 0;
    cin >> n;
    for (int x = 0; x <= n; ++x) {
        for (int y = x; y <= n; ++y) {
            sum += x + y;
        }
    }
    cout << sum << '\n';
    return 0;
}
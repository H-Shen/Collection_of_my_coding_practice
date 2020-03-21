#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    cin >> n;
    n /= 52;
    int x_ = -1;
    int k_ = -1;
    for (int x = 0; x <= n; ++x) {
        for (int k = 0; k <= n; ++k) {
            if (7*x+21*k==n && k >= 1 && 1 <= x && x <= 100) {
                if (x > x_) {
                    x_ = x;
                    k_ = k;
                }
            }
        }
    }
    cout << x_ << '\n' << k_ << endl;

    return 0;
}

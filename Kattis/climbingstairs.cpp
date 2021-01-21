// https://open.kattis.com/problems/climbingstairs

#include <bits/extc++.h>

using namespace std;
using ll = long long;
using ld = long double;

int f(int n, int r, int k) {
    if (n % 2 != r % 2 && n > k + abs(k - r)) {
        return 1;
    }
    return 0;
}

int main() {

    int n, r, k;
    cin >> n >> r >> k;
    cout << max(n, k + abs(r - k)) + r + f(n, r, k) << '\n';

    return 0;
}

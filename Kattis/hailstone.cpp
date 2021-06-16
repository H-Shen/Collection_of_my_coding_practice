// https://open.kattis.com/problems/hailstone

#include <bits/extc++.h>

using namespace std;
using ull = unsigned long long;

int main() {
    ull sum = 0;
    ull n;
    cin >> n;
    while (true) {
        sum += n;
        if (n == 1) break;
        if (n & 1) {
            n = 3*n + 1;
        } else {
            n >>= 1;
        }
    }
    cout << sum << '\n';
    return 0;
}

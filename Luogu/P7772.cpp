#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    int a, i;
    cin >> a >> i;
    int n = a * i;
    while ((int) ceil(n * 1.0 / a) >= i) {
        --n;
    }
    while ((int) ceil(n * 1.0 / a) < i) {
        ++n;
    }
    cout << n << '\n';
    return 0;
}
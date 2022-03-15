// https://open.kattis.com/problems/testdrive

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b > a && b > c) {
        cout << "turned" << '\n';
        return 0;
    }
    if (b < a && b < c) {
        cout << "turned" << '\n';
        return 0;
    }
    int v0 = abs(a - b);
    int v1 = abs(b - c);
    if (v0 == v1) {
        cout << "cruised" << '\n';
    }
    else if (v0 > v1) {
        cout << "braked" << '\n';
    }
    else {
        cout << "accelerated" << '\n';
    }

    return 0;
}

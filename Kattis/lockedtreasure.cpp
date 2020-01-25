// https://open.kattis.com/problems/lockedtreasure
//
#include <bits/extc++.h>

using namespace std;

inline static
string printInt128(__int128 a) { // prints as decimal
    if (!a) {
        return "0";
    }
    string s;
    while (a) {
        s = char(llabs(static_cast<long long>(a % 10)) + '0') + s;
        if (-10 < a && a < 0) {
            s = '-' + s;
        }
        a /= 10;
    }
    return s;
}

// C(n, m) = n! / (m! * (n - m)!)
inline static
string comb(int n, int m) {
    __int128 temp0 = 1;
    for (int i = n - m + 1; i <= n; ++i) {
        temp0 *= i;
    }
    __int128 temp1 = 1;
    for (int i = 1; i <= m; ++i) {
        temp1 *= i;
    }
    return printInt128(temp0 / temp1);
}

int main() {

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cout << comb(n, m - 1) << endl;
    }

    return 0;
}

// https://open.kattis.com/problems/slatkisi
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

inline static
ll powerOfTen(const ll &n) {
    if (n <= 0) {
        return 1;
    }
    ll temp = 1;
    for (ll i = 0; i < n; ++i) {
        temp *= 10;
    }
    return temp;
}

int main() {

    ll c, k;
    cin >> c >> k;

    // get length of c
    ll length = to_string(c).size();

    // get 10^k
    ll temp = powerOfTen(k);

    // Case 1: k = 0
    if (k == 0) {
        cout << c << endl;
    }
    // Case 2: k >= length
    else if (k > length) {
        cout << 0 << endl;
    }
    // Case 3:
    else {
        ll tail = c % temp;
        if (tail >= temp / 2) {
            ll add = temp - tail;
            c += add;
            cout << c << endl;
        } else {
            string result = to_string(c);
            auto it = result.rbegin();
            for (ll i = 0; i < k; ++i) {
                *it = '0';
                ++it;
            }
            cout << result << endl;
        }
    }


    return 0;
}

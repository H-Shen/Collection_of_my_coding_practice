// https://open.kattis.com/problems/pauleigon
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    ll n, p, q;
    cin >> n >> p >> q;
    ll temp = p + q + 1;
    ll k = temp / n;
    ll m = temp % n;
    bool isPaul;
    if (k % 2 != 0) {
        isPaul = m == 0;
    } else {
        isPaul = m != 0;
    }
    if (isPaul) {
        cout << "paul";
    } else {
        cout << "opponent";
    }
    cout << endl;

    return 0;
}

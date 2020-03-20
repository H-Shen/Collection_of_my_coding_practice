// https://open.kattis.com/problems/alexandbarb
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int m, n, k;
    cin >> k >> m >> n;
    if ( k % (m + n) >= m ) {
        cout << "Alex" << endl;
    } else {
        cout << "Barb" << endl;
    }

    return 0;
}

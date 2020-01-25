// https://open.kattis.com/problems/dasblinkenlights
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int p, q, s;
    cin >> p >> q >> s;
    for (int i = 1; i <= s; ++i) {
        if (i % p == 0 && i % q == 0) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;

    return 0;
}

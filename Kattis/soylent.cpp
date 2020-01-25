// https://open.kattis.com/problems/soylent
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, val;
    cin >> n;
    while (n--) {
        cin >> val;
        if (val % 400 == 0) {
            cout << val / 400 << endl;
        } else {
            cout << val / 400 + 1 << endl;
        }
    }

    return 0;
}

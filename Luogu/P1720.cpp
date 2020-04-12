#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
    } else if (n == 1) {
        cout << 1;
    } else if (n == 2) {
        cout << 1;
    } else {
        ll a = 1;
        ll b = 1;
        ll temp;
        for (int i = 0; i < n - 1; ++i) {
            temp = b;
            b = a + b;
            a = temp;
        }
        cout << a;
    }


    cout << ".00" << endl;

    return 0;
}

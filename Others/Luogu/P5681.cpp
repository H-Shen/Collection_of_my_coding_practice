#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll a, b, c;
    cin >> a >> b >> c;
    if (a * a > b * c) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }
    cout << endl;

    return 0;
}

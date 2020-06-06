#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    string a, b;
    cin >> a >> b;
    reverse(b.begin(), b.end());
    if (a == b) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';

    return 0;
}
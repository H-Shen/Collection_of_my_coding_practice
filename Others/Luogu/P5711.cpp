#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0)) {
        cout << 1;
    } else {
        cout << 0;
    }
    cout << '\n';

    return 0;
}
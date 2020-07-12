#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll k, w, n;
    cin >> k >> n >> w;
    ll result = (1 + w) * w / 2 * k - n;
    if (result < 0) result = 0;
    cout << result << endl;

    return 0;
}

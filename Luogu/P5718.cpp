#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, val;
    int minVal = numeric_limits<int>::max();
    cin >> n;
    while (n--) {
        cin >> val;
        minVal = min(minVal, val);
    }
    cout << minVal << '\n';
    return 0;
}
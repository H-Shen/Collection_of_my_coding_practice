#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, val;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();
    cin >> n;
    while (n--) {
        cin >> val;
        minVal = min(minVal, val);
        maxVal = max(maxVal, val);
    }
    cout << abs(minVal - maxVal) << '\n';
    return 0;
}
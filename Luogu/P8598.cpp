#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    constexpr int MAXN = 1e5+5;
    int freq[MAXN]{};
    int val;
    int minVal = numeric_limits<int>::max();
    while (cin >> val) {
        ++freq[val];
        minVal = min(minVal, val);
    }
    for (int i = minVal; i < MAXN; ++i) {
        if (freq[i] > 0 && freq[i+1] == 0 && freq[i+2] > 0) {
            cout << i+1 << ' ';
            break;
        }
    }
    for (int i = minVal; i < MAXN; ++i) {
        if (freq[i] > 1) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}
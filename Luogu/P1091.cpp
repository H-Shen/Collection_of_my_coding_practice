#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto&i : h) cin >> i;
    vector<int> dpLeft(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (h[j] < h[i]) {
                dpLeft[i] = max(dpLeft[i], dpLeft[j] + 1);
            }
        }
    }
    vector<int> dpRight(n, 1);
    for (int i = n-1; i >= 0; --i) {
        for (int j = n-1; j > i ; --j) {
            if (h[i] > h[j]) {
                dpRight[i] = max(dpRight[i], dpRight[j] + 1);
            }
        }
    }
    int ans = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i) {
        ans = min(ans, n - (dpLeft[i] + dpRight[i] - 1));
    }
    cout << ans << '\n';
    return 0;
}

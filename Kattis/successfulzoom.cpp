// https://open.kattis.com/problems/successfulzoom

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
using ll = long long;

constexpr int MAXN = 1e5+5;
constexpr int INF = 0x3f3f3f3f;

int x[MAXN];
int n;

bool check(int mid) {
    int q = n / mid;
    if (q == 1) return false;
    for (int i = 1; i <= q-1; ++i) {
        if (x[i*mid] >= x[(i+1)*mid]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int k = 1; k <= n; ++k) {
        if (check(k)) {
            cout << k << '\n';
            return 0;
        }
    }
    cout << "ABORT!" << '\n';
    return 0;
}

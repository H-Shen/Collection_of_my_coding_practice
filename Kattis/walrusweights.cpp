// https://open.kattis.com/problems/walrusweights

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 1005;
constexpr int TARGET = 1000;
int dp1[MAXN];
int dp2[MAXN];
int n, sum;
int val[MAXN];
bool flag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    flag = true;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        sum += val[i];
        if (val[i] <= TARGET) {
            flag = false;
        }
    }
    if (flag) {
        cout << *min_element(val, val+n) << '\n';
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = TARGET; j >= val[i]; --j) {
            int temp = dp1[j - val[i]] + val[i];
            if (temp > dp1[j]) {
                dp1[j] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 2 * TARGET - dp1[TARGET]; j >= val[i]; --j) {
            int temp = dp2[j - val[i]] + val[i];
            if (temp > dp2[j]) {
                dp2[j] = temp;
            }
        }
    }
    int ans1 = dp1[TARGET];
    int ans2 = dp2[2 * TARGET - dp1[TARGET]];
    if (ans2 < TARGET) {
        cout << ans1 << '\n';
        return 0;
    }
    int diff1 = TARGET - ans1;
    int diff2 = ans2 - TARGET;
    if (diff1 >= diff2) {
        cout << ans2 << '\n';
    }
    else {
        cout << ans1 << '\n';
    }

    return 0;
}

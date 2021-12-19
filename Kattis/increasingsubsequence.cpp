// https://open.kattis.com/problems/increasingsubsequence

#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 205;
int n;
int dp[MAXN];
int A[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true) {
        cin >> n;
        if (n == 0) break;
        fill(dp, dp + n, 1);
        memset(A, 0, sizeof A);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (A[j] < A[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int length = *max_element(dp, dp+n);
        int index = 0;
        for (int i = n-1; i >= 0; --i) {
            if (dp[i] == length) {
                index = i;
                break;
            }
        }
        int lengthCopy = length;
        vector<int> ans(length);
        for (int i = index; i >= 0; --i) {
            if (dp[i] == lengthCopy) {
                ans[lengthCopy-1] = A[i];
                --lengthCopy;
            }
        }
        cout << length;
        for (auto&i : ans) {
            cout << ' ' << i;
        }
        cout << '\n';
    }
    return 0;
}

// https://open.kattis.com/problems/alphabet
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int lengthOfLIS(const string &s) {
    int n = static_cast<int>(s.size());
    vector<int> dp(n, 1);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (s[i] > s[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {

    string s;
    cin >> s;
    cout << (26 - lengthOfLIS(s)) << endl;

    return 0;
}

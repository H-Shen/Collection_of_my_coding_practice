// https://www.nowcoder.com/practice/cff52ae345a248ea94c8c0cc2d278474

#include <iostream>
#include <algorithm>

using namespace std;

void GetUglyNumber_Solution(int index) {
    if (index <= 0) {
        cout << 0 << endl;
        return;
    } else if (index == 1) {
        cout << 1 << endl;
        return;
    }
    int a = 0;
    int b = 0;
    int c = 0;
    int *dp = new int[index];
    dp[0] = 1;
    for (int i = 1; i < index; i++) {
        dp[i] = min(dp[a] * 2, min(dp[b] * 3, dp[c] * 5));
        if (dp[i] == dp[a] * 2) {
            ++a;
        }
        if (dp[i] == dp[b] * 3) {
            ++b;
        }
        if (dp[i] == dp[c] * 5) {
            ++c;
        }
    }

    cout << dp[index - 1] << endl;
    delete[](dp);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    GetUglyNumber_Solution(n);
    return 0;
}
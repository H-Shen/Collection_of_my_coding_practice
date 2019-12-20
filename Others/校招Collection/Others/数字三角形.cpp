// write your code here cpp
// https://www.nowcoder.com/practice/88c6d56d78974869aac605a0d26deded

#include <bits/stdc++.h>

using namespace std;

int maximumTotal(const vector<vector<int> > &triangle) {

    int n = static_cast<int>(triangle.size());

    if (n == 0) {
        return 0;
    }

    vector<vector<int> > dp(static_cast<unsigned long>(n));
    int i, j;

    for (i = 0; i < n; ++i) {
        dp[i].resize(static_cast<unsigned long>(i) + 1);
    }

    dp[0][0] = triangle[0][0];

    //dp[i][0]
    for (i = 1; i < n; ++i) {
        dp[i][0] = triangle[i][0] + dp[i - 1][0];
    }

    //dp[i][j]
    for (i = 1; i < n; ++i) {
        for (j = 1; j <= i; ++j) {
            if (i == j) {
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            } else {
                dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }
    }

    int res = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    return res;
}


int main() {

    int n, i, j;
    while (~scanf("%d", &n)) {
        vector<vector<int> > a(static_cast<unsigned long>(n));
        for (i = 0; i < n; ++i) {
            a.at(static_cast<unsigned long>(i)).resize(static_cast<unsigned long>(i) + 1);
            for (j = 0; j < i + 1; ++j) {
                scanf("%d", &a.at(static_cast<unsigned long>(i)).at(static_cast<unsigned long>(j)));
            }
        }
        printf("%d\n", maximumTotal(a));
    }
    return 0;
}
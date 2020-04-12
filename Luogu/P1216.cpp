#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
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

    size_t n, i, j;
    scanf("%zd", &n);
    vector<vector<int> > A(n);
    for (i = 0; i < n; ++i) {
        A.at(i).resize(i + 1);
        for (j = 0; j < i + 1; ++j) {
            scanf("%d", &A.at(i).at(j));
        }
    }
    printf("%d\n", maximumTotal(A));

    return 0;
}
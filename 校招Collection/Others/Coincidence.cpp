// https://www.nowcoder.com/practice/f38fc44b43cf44eaa1de407430b85e69

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 105;
char a[MAXN];
char b[MAXN];

auto LCS = [](const auto & A, const auto & B) {

    int len_A = static_cast<int>(A.size());
    int len_B = static_cast<int>(B.size());
    if (len_A == 0 || len_B == 0) {
        return 0;
    }
    vector<vector<int> > dp(len_A, vector<int>(len_B));
    for (int a = 0; a < len_A; a++) {
        for (int b = 0; b < len_B; b++) {
            if (a) dp[a][b] = max(dp[a][b], dp[a-1][b]);
            if (b) dp[a][b] = max(dp[a][b], dp[a][b-1]);
            if (A[a] == B[b])
                dp[a][b] = max(dp[a][b], ((a && b) ? dp[a-1][b-1] : 0) + 1);
        }
    }
    int ret = dp[len_A - 1][len_B - 1];
    return ret;
};

int main() {
    scanf("%s %s", a, b);
    printf("%d\n", LCS(string(a), string(b)));
    return 0;
}

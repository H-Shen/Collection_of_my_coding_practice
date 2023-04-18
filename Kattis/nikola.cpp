// https://open.kattis.com/problems/nikola
//
#include <bits/extc++.h>

using namespace std;

constexpr int MAXN = 1005;
constexpr int INF = 0x3f3f3f3f;

int w[MAXN];
int n;
int dp[MAXN][MAXN];

int solve(int current_index, int jump) {
	if (current_index == n - 1) {
		return w[n - 1];
	}
	else if (current_index < 0 || current_index > n - 1) {
		return INF;
	}
	if (dp[current_index][jump] != -1) {
		return dp[current_index][jump];
	}
	dp[current_index][jump] = w[current_index] + min(solve(current_index - jump, jump), solve(current_index + jump + 1, jump + 1));
	return dp[current_index][jump];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	memset(dp, -1, sizeof dp);
	cout << solve(1, 1) << '\n';
	return 0;
}

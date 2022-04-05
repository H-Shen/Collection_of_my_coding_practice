using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f;

class Solution {
public:
    unordered_map<ll,ll> dp;
    ll solve(vector<int>& coins, ll amount) {
        if (amount < 0) {
            return INF;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp.count(amount) > 0) {
            return dp[amount];
        }
        dp[amount] = INF;
        for (auto&i : coins) {
            dp[amount] = min(dp[amount], solve(coins, amount - i) + 1);
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.clear();
        ll result = solve(coins, amount);
        return (result == INF) ? -1 : result;
    }
};
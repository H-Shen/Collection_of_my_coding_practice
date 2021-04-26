using ll = long long;
constexpr ll INF = 0x3f3f3f3f3f3f;

class Solution {
public:
    unordered_map<ll, ll> dp;
    vector<ll> Coins;
    ll solve(ll amount) {
        if (amount < 0) {
            return INF;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp.find(amount) != dp.end()) {
            return dp[amount];
        }
        dp[amount] = INF;
        for (const auto &i : Coins) {
            dp[amount] = min(dp[amount], solve(amount - i) + 1); //
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = (int)coins.size();
        Coins.resize(n);
        for (int i = 0; i < n; ++i) {
            Coins[i] = coins[i];
        }
        ll temp = solve(amount);
        if (temp == INF) {
            temp = -1;
        }
        return temp;
    }
};
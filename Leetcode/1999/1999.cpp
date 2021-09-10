using ll = long long;

class Solution {
public:
    ll ans;
    void dfs(ll cur, ll digit1, ll digit2, ll k) {
        if (cur > ((ll)numeric_limits<int>::max())) {
            return;
        }
        if (cur > k && cur % k == 0) {
            ans = min(ans, cur);
            return;
        }
        if (cur == -1) {
            dfs(digit1, digit1, digit2, k);
            dfs(digit2, digit1, digit2, k);
        }
        else {
            dfs(cur*10+digit1, digit1, digit2, k);
            dfs(cur*10+digit2, digit1, digit2, k);
        }
    }
    int findInteger(int k, int digit1, int digit2) {
        if (digit1 == 0 && digit2 == 0) {
            return -1;
        }
        ans = numeric_limits<ll>::max();
        if (digit1 == 0) {
            dfs(digit2, digit1, digit2, k);
        }
        else if (digit2 == 0) {
            dfs(digit1, digit1, digit2, k);
        }
        else {
            dfs(-1, digit1, digit2, k);
        }
        return ans == numeric_limits<ll>::max() ? -1 : (int)ans;
    }
};
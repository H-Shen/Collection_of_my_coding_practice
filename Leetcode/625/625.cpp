using ll = long long;

class Solution {
public:
    ll ans;
    void dfs(ll num, ll cur) {
        // once one solution is found, stop the dfs
        if (ans != numeric_limits<ll>::max() || cur > (ll)numeric_limits<int>::max() || cur >= ans) {
            return;
        }
        if (num <= 9) {
            cur = 10*cur + num;
            if (cur <= (ll)numeric_limits<int>::max()) {
                ans = cur;
            }
            return;
        }
        for (ll i = 9; i >= 1; --i) {
            if (num % i == 0) {
                dfs(num / i, cur*10+i);
            }
        }
    }
    int smallestFactorization(int num) {
        if (num <= 9) {
            return num;
        }
        ans = numeric_limits<ll>::max();
        ll numl = num;
        for (ll i = 9; i >= 1; --i) {
            if (ans != numeric_limits<ll>::max()) {
                break;
            }
            if (numl % i == 0 && i < ans) {
                dfs(numl / i, i);
            }
        }
        if (ans == numeric_limits<ll>::max()) {
            return 0;
        }
        string temp = to_string(ans);
        sort(temp.begin(),temp.end());
        try {
            return stoi(temp);
        } catch (...) {
            return 0;
        }
    }
};
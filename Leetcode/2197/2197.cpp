using ll = long long;

ll bingcd(ll a, ll b) {
    if (a < 0 || b < 0) return bingcd(abs(a), abs(b));
    if (!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (ans.empty()) {
                ans.emplace_back(nums[i]);
                continue;
            }
            ll Gcd = bingcd(nums[i],ans.back());
            if (Gcd > 1) {
                ll temp = (ll)nums[i]*ans.back()/Gcd;
                ans.pop_back();
                ans.emplace_back(temp);
            }
            else {
                ans.emplace_back(nums[i]);
            }
            while (ans.size() >= 2 && (Gcd = bingcd(ans[ans.size()-1],ans[ans.size()-2])) > 1) {
                ll temp = ans[ans.size()-1]*ans[ans.size()-2]/Gcd;
                ans.pop_back();
                ans.pop_back();
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};
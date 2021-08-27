using ll = long long;
constexpr ll MOD = 1e9+7;

vector<ll> pre;
ll range_sum(int l, int r) {
    if (l == 0) {
        return pre[r];
    }
    return pre[r] - pre[l-1];
}

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        vector<ll>().swap(pre);
        int n = (int)nums.size();
        stack<int> s;
        vector<int> l(n);
        vector<int> r(n, n-1);
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                r[s.top()] = i-1;
                s.pop();
            }
            if (!s.empty()) {
                l[i] = s.top()+1;
            }
            s.push(i);
        }
        
        pre.resize(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i-1]+nums[i];
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, range_sum(l[i], r[i]) * nums[i]);
        }
        return ans % MOD;
    }
};
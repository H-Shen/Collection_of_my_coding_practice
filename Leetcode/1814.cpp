using ll = long long;
constexpr ll MOD = 1e9+7;

class Solution {
public:
    ll rev(ll n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoll(s);
    }
    int countNicePairs(vector<int>& nums) {
        int n = (int)nums.size();
        unordered_map<ll,int> unmap;
        for (int i = 0; i < n; ++i) {
            ++unmap[(ll)nums[i] - rev(nums[i])];
        }
        ll ans = 0;
        for (const auto &[k,v] : unmap) {
            if (v > 1) {
                ans += (ll)v*(v-1)/2;   // C(n,2)
            }
        }
        return ans % MOD;
    }
};
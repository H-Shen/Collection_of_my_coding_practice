class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    int sumOfFlooredPairs(vector<int>& nums) {
        using ll = long long;
        constexpr ll MOD = 1e9+7;
        unordered_map<ll,ll> freq;
        for (const auto &i : nums) {
            ++freq[i];
        }
        ll maxVal = *max_element(nums.begin(),nums.end());
        vector<ll> vals(maxVal+1);
        for (const auto &[k,v] : freq) {
            for (ll i = k; i < maxVal+1; i += k) {
                vals[i] += freq[k];
            }
        }
        for (int i = 1; i < maxVal+1; ++i) {
            vals[i] += vals[i-1];
        }
        ll result = 0;
        for (const auto &i : nums) {
            result = (result + vals[i]) % MOD;
        }
        result %= MOD;
        return result;
    }
};
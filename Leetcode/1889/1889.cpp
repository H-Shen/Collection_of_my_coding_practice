using ll = long long;
constexpr ll MOD = 1e9+7;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(), packages.end());
        int n = (int)packages.size();
        ll sum = accumulate(packages.begin(),packages.end(),ll(0));
        ll ans = numeric_limits<ll>::max();
        for (auto &k : boxes) {
            sort(k.begin(), k.end());
            // Case 1: The biggest box cannot contain the biggest package
            if (k.back() < packages.back()) {
                continue;
            }
            // Case 2:
            ll temp = 0;
            int i = 0;
            for (const auto &box : k) {
                int j = lower_bound(packages.begin(), packages.end(), box+1) - packages.begin();
                temp += (ll)box*(j-i);
                i = j;
            }
            ans = min(ans, temp);
        }
        return (ans == numeric_limits<ll>::max()) ? -1 : (int)((ans - sum) % MOD);
    }
};
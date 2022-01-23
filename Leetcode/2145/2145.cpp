using ll = long long;

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = (int)differences.size();
        vector<ll> pre(n+1);
        pre[0] = 0; // the first item of the original array
        for (int i = 1; i < n+1; ++i) {
            pre[i] = pre[i-1] + (ll)differences[i-1];
        }
        ll upper_bound = (ll)upper - *max_element(pre.begin(),pre.end());
        ll lower_bound = (ll)lower - *min_element(pre.begin(),pre.end());
        ll ans = max(0LL, upper_bound - lower_bound + 1LL);
        return (int)ans;
    }
};
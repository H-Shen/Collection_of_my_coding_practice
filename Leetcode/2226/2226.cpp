using ll = long long;

class Solution {
public:
    bool check(vector<int>& candies, ll mid, ll k) {
        ll temp;
        for (auto&i : candies) {
            temp = i;
            if (temp < mid) continue;
            k -= temp / mid;
            if (k <= 0) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        ll l = 1;
        ll r = (ll)(*max_element(candies.begin(),candies.end()));
        ll mid;
        ll ans = numeric_limits<ll>::min();
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(candies, mid, k)) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
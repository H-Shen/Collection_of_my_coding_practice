using ll = long long;

constexpr ll MAXN = 1e15;

class Solution {
public:
    bool check(ll totalTime, vector<int>& time, ll totalTrips) {
        ll counter = 0;
        for (auto&i : time) {
            counter += totalTime / (ll)i;
            if (counter >= totalTrips) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = (int)time.size();
        ll l = 1, r = MAXN;
        ll mid;
        ll ans = numeric_limits<ll>::max();
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(mid, time, totalTrips)) {
                ans = min(ans, mid);
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
using ll = long long;

class Solution {
public:
    inline
    bool check(ll time, vector<int>& ranks, ll cars) {
        ll totalCarToRepair = 0;
        ll maxCarToRepair;
        for (auto& r : ranks) {
            maxCarToRepair = sqrt(time*1.0/(ll)r);
            while (maxCarToRepair*maxCarToRepair*r > time) {
                --maxCarToRepair;
            }
            totalCarToRepair += maxCarToRepair;
            if (totalCarToRepair >= cars) {
                return true;
            }
        }
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 9223372036854775806;
        ll mid;
        ll ans = numeric_limits<ll>::max();
        while (l <= r) {
            mid = l + ((r-l)>>1);
            if (check(mid, ranks, cars)) {
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
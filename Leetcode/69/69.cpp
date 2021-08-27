using ll = long long;

class Solution {
public:
    int mySqrt(int x) {
        constexpr double MAXN = 1e-4;
        double l = 0;
        double r = x * 1.0;
        double mid;
        while (r-l > MAXN) {
            mid = (l+r) / 2.0;
            if (mid*mid>=x*1.0) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ll x_ll = x;
        ll ans = l;
        if ((ans+1)*(ans+1) <= x_ll) return (int)(ans+1);
        return (int)ans;
    }
};
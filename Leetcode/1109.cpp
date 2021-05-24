struct BIT {
    using ll = long long;
    vector<ll> t1, t2;
    int N;
    BIT(int n) : N(n) {
        t1.resize(N);
        t2.resize(N);
    }
    ll sum(const vector<ll> &t, int n) {
        ll a(0);
        while (n) {
            a += t[n];
            n -= (n & (-n));
        }
        return a;
    }
    ll rsum(int n) {
        return sum(t1,n)*n-sum(t2,n);
    }
    ll rsum(int l, int r) {
        return rsum(r)-rsum(l-1);
    }
    void upd(vector<ll> &t, int n, ll v) {
        while (n < N) {
            t[n] += v;
            n += (n & (-n));
        }
    }
    void rupd(int l, int r, ll v) {
        upd(t1,l,v);
        upd(t1,r+1,-v);
        upd(t2,l,v*(l-1));
        upd(t2,r+1,-v*r);
    }
};

class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        BIT t(n+5);
        vector<int> ans(n);
        for (const auto &i : bookings) {
            t.rupd(i[0],i[1],i[2]);
        }
        for (int i = 0; i < n; ++i) {
            ans[i] = t.rsum(i+1,i+1);
        }
        return ans;
    }
};
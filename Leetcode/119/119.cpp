using ll = long long;

class Solution {
public:
    // C(n, m) = ((n-m+1)(n-m+2)...(n-m+m))/(m(m-1)(m-2)...2*1)
    ll comb(ll n, ll m) {
        if (m > n - m) m = n - m;
        ll result = 1;
        for (ll i = 1; i <= m; ++i) {
            result = result * (n - m + i) / i;
        }
        return result;
    }
    vector<int> getRow(int rowIndex) {        
        vector<int> result(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            result[i] = (int)comb(rowIndex, i);
        }
        return result;
    }
};
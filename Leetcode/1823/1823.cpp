using ll = long long;
ll quickJoseph(ll n, ll k, ll s = 1) {

    if (k == 1)
        return (n - 1 + s) % n;
    ll res = 0;

    for (ll i = 2; i <= n;) {
        if (res + k < i) {
            ll leap;
            if ((i - res - 1) % (k - 1) == 0)
                leap = (i - res - 1) / (k - 1) - 1;
            else
                leap = (i - res - 1) / (k - 1);
            if (i + leap > n)
                return ((res + (n + 1 - i) * k) + s) % n;
            i += leap;
            res += leap * k;
        } else {
            res = (res + k) % i;
            i++;
        }
    }
    return (res + s) % n;
}

class Solution {
public:
    int findTheWinner(int n, int k) {
        int p = quickJoseph(n, k);
        if (p == 0) p = n;
        return p;
    }
};
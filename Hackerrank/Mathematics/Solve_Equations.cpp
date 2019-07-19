#include <cstdio>
#include <cmath>

#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    return (b > 0) ? gcd(b, a % b) : a;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll r = exgcd(b, a % b, x, y);
    ll tp = x;
    x = y;
    y = tp - a / b * y;
    return r;
}

vector < pair <ll, ll> > allSolutions(ll a, ll b, ll c, ll d, ll &x, ll &y) {

    vector < pair <ll, ll> > res;
    d = exgcd(a, b, x, y);

    if (a && b == 0) {
        pair <ll, ll> tmp = {c / a, -c / a};
        res.push_back(tmp);
        return res;
    }
    if (a == 0 && b) {
        pair <ll, ll> tmp = {1, c / b};
        res.push_back(tmp);
        return res;
    }

    a /= d, b/= d, c /= d;
    x *= c;
    y *= c;

    ll x0 = x, y0 = y;

    ll tx = x;
    x %= b;
    if (x <= 0) x += (ll)abs(b * 1.0);
    ll k = (tx - x) / b;
    y += k * a;

    ll A = a / gcd(a, b);
    ll B = b / gcd(a, b);

    ll t = (x - x0) / B;

    while (1) {
        x = x0 + B * t;
        y = y0 - A * t;
        pair <ll, ll> tmp = {x, y};
        res.push_back(tmp);
        if (a * x > c) {
            break;
        }
        ++t;
    }
    return res;
}

bool cmp( const pair <ll, ll> &a, const pair <ll, ll> &b) {
    ll a_len = a.first * a.first + a.second * a.second;
    ll b_len = b.first * b.first + b.second * b.second;
    return (a_len < b_len);
}

int main() {

    ll a, b, c;
    ll d = 0;
    ll x, y;
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%lld %lld %lld", &a, &b, &c);
        vector <pair <ll, ll> > A = allSolutions(a, b, c, d, x, y);
        sort(A.begin(), A.end(), cmp);
        printf("%lld %lld\n", A[0].first, A[0].second);
    }
    return 0;
}

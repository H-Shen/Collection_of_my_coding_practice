// https://ac.nowcoder.com/acm/problem/14268

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

struct Point {
    ll x;
    ll y;

    //x + y
    ll a;
    //-x + y
    ll b;
    //x - y
    ll c;
    //-x - y
    ll d;
};

inline static
bool cmp_a(const Point &p1, const Point &p2) { return p1.a < p2.a; }

inline static
bool cmp_b(const Point &p1, const Point &p2) { return p1.b < p2.b; }

inline static
bool cmp_c(const Point &p1, const Point &p2) { return p1.c < p2.c; }

int main() {
    int n;
    ll tmp;
    scanf("%d", &n);
    if (n == 0) {
        printf("0\n");
        return 0;
    }

    vector<Point> Points(n);

    for (ll i = 0; i < n; ++i) {
        scanf("%lld", &tmp);
        Points[i].x = (i + 1) * (i + 1);
        Points[i].y = tmp * tmp;
        Points[i].a = Points[i].x + Points[i].y;
        Points[i].b = -Points[i].x + Points[i].y;
        Points[i].c = Points[i].x - Points[i].y;
        Points[i].d = -Points[i].x - Points[i].y;
    }

    vector<ll> res;
    auto it_a = minmax_element(Points.begin(), Points.end(), cmp_a);
    auto it_b = minmax_element(Points.begin(), Points.end(), cmp_b);
    auto it_c = minmax_element(Points.begin(), Points.end(), cmp_c);

    res.push_back((*it_a.second).a - (*it_a.first).a);
    res.push_back((*it_b.second).b - (*it_b.first).b);
    res.push_back((*it_c.second).c - (*it_a.first).c);
    res.push_back((*it_a.second).d - (*it_a.first).d);

    printf("%lld\n", *max_element(res.begin(), res.end()));

    return 0;
}
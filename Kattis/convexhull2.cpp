// https://open.kattis.com/problems/convexhull2

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pt = pair<ll,ll>;

ll ccw(pt a, pt b, pt c) {
    return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}

vector<pt> pts;
int n;
void convexHull() {
    vector<pt>  b,t;
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    for (const pt &p : pts) {
        // dont forget to contain intermediate collinear points
        while (b.size() >= 2 && ccw(b[b.size()-2], b[b.size()-1], p) < 0) {
            b.pop_back();
        }
        b.emplace_back(p);
        while (t.size() >= 2 && ccw(t[t.size()-2], t[t.size()-1], p) > 0) {
            t.pop_back();
        }
        t.emplace_back(p);
    }
    pts = b;
    for (int i = (int)(t.size()-2); i > 0; --i) {
        pts.emplace_back(t[i]);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    string op;
    ll x,y;
    while (n--) {
        cin >> x >> y >> op;
        if (op[0] == 'Y') {
            pts.emplace_back(x,y);
        }
    }
    convexHull();
    cout << pts.size() << '\n';
    for (const auto &i : pts) {
        cout << i.first << ' ' << i.second << '\n';
    }

    return 0;
}

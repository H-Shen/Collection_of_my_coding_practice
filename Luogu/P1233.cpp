
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    struct Point {
        int x,y;
    };
    int n;
    cin >> n;
    list<Point> vec(n);
    for (auto&i : vec) {
        cin >> i.x >> i.y;
    }
    vec.sort([](const Point& l, const Point& r) {
        if (l.x == r.x) {
            return l.y > r.y;
        }
        return l.x > r.x;
    });
    int ans = 0;
    while (!vec.empty()) {
        ++ans;
        int current_x = vec.begin()->x;
        int current_y = vec.begin()->y;
        vec.erase(vec.begin());
        for (auto iter = vec.begin(); iter != vec.end(); ) {
            if (iter->x <= current_x && iter->y <= current_y) {
                current_x = iter->x;
                current_y = iter->y;
                iter = vec.erase(iter);
            }
            else {
                ++iter;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
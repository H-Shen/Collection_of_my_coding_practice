// https://open.kattis.com/problems/junk
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    int x1,x2,y1,y2,z1,z2,r1,r2,vx1,vx2,vy1,vy2,vz1,vz2;
    int a,b,c;
    while (t--) {
        cin >> x1 >> y1 >> z1 >> r1 >> vx1 >> vy1 >> vz1;
        cin >> x2 >> y2 >> z2 >> r2 >> vx2 >> vy2 >> vz2;
        a = (vx1-vx2)*(vx1-vx2)+(vy1-vy2)*(vy1-vy2)+(vz1-vz2)*(vz1-vz2);
        b = 2*(x1-x2)*(vx1-vx2)+2*(y1-y2)*(vy1-vy2)+2*(z1-z2)*(vz1-vz2);
        c = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)-(r1+r2)*(r1+r2);
        // cout << a << ' ' << b << ' ' << c << '\n';
        if (a == 0) {
            cout << "No collision" << '\n';
            continue;
        }
        int delta = b*b-4*a*c;
        if (delta < 0) {
            cout << "No collision" << '\n';
            continue;
        }
        double res1 = (-b+ sqrt(delta)) / (2.0 * a);
        double res2 = (-b- sqrt(delta)) / (2.0 * a);
        double resMin = min(res1, res2);
        if (resMin <= 0) {
            cout << "No collision" << '\n';
            continue;
        }
        cout << setprecision(3) << fixed << resMin << '\n';
    }
    return 0;
}

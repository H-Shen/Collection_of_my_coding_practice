// https://open.kattis.com/problems/associativeexponents

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int sgn(const double &x) {
    const static double EPS =1e-7;
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int a,b,c;
    cin >> a >> b >> c;
    if (a == 1 || c == 1) {
        cout << "What an excellent example!" << '\n';
        return 0;
    }
    if (sgn((c-1)* log(b) - log(c)) == 0) {
        cout << "What an excellent example!" << '\n';
    } else {
        cout << "Oh look, a squirrel!" << '\n';
    }

    return 0;
}

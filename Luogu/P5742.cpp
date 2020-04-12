#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;

inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int id, study, extend;
    while (n--) {
        cin >> id >> study >> extend;
        if (study + extend > 140 && sgn(study * 0.7 + extend * 0.3 - 80.0) > 0) {
            cout << "Excellent\n";
        } else {
            cout << "Not excellent\n";
        }
    }

    return 0;
}
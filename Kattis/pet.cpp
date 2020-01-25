// https://open.kattis.com/problems/pet
#include <bits/extc++.h>

using namespace std;

const double eps = 1e-8;
const int maxn = 5;

inline int sgn(double a) {
    if (a < -eps) return -1;
    if (a > eps) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);

    int winnerNumber = -1;
    int maxVal = -1;
    int a, b, c, d, sum;

    for (int i = 0; i < maxn; ++i) {
        cin >> a >> b >> c >> d;
        sum = a + b + c + d;
        if (sum > maxVal) {
            maxVal = sum;
            winnerNumber = i + 1;
        }
    }
    cout << winnerNumber << ' ' << maxVal << endl;
    return 0;
}

// https://open.kattis.com/problems/carousel
//
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

    int n, m, a, b;
    while (true) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) {
            break;
        }
        vector<tuple<int, int, double> > A;
        double temp;
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            if (a <= m) {
                temp = a * 1.0 / b;
                A.emplace_back(a, b, temp);
            }
        }
        if (A.empty()) {
            printf("No suitable tickets offered\n");
        } else {
            sort(A.begin(), A.end(), [](const tuple<int, int, double> &lhs, const tuple<int, int, double> &rhs) {
                if (sgn(get<2>(lhs) - get<2>(rhs)) == 0) {
                    return get<1>(lhs) > get<1>(rhs);
                }
                return sgn(get<2>(lhs) - get<2>(rhs)) > 0;
            });
            printf("Buy %d tickets for $%d\n", get<0>(A.front()), get<1>(A.front()));
        }
    }

    return 0;
}

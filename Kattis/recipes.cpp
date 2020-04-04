// https://open.kattis.com/problems/recipes
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr double EPS = 1e-7;
constexpr int MAXN = 25;
char s[MAXN];

inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

struct Node {
    string s;
    double w, per, ans;
};

int main() {

    int t, r, p, d, pos;
    double w, per;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        scanf("%d %d %d", &r, &p, &d);
        vector<Node> A(r);
        pos = 0;
        for (int j = 0; j < r; ++j) {
            scanf("%s %lf %lf", s, &w, &per);
            A.at(j).s = s;
            A.at(j).w = w;
            A.at(j).per = per;
            if (sgn(per - 100.0) == 0) {
                pos = j;
            }
        }
        A.at(pos).ans = d * 1.0 / p * A.at(pos).w;
        for (int j = 0; j < r; ++j) {
            if (j != pos) {
                A.at(j).ans = A.at(pos).ans * A.at(j).per / 100.0;
            }
        }
        printf("Recipe # %d\n", i);
        for (int j = 0; j < r; ++j) {
            printf("%s %.1lf\n", A.at(j).s.c_str(), A.at(j).ans);
        }
        printf("----------------------------------------\n");
    }

    return 0;
}

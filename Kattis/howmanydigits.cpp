// https://open.kattis.com/problems/howmanydigits
#include <bits/extc++.h>

using namespace std;

const double PI = acos(-1.0);
const double ln_10 = log(10.0);

inline
double reback(int N) {
    return ceil((N * log(double(N)) - N + 0.5 * log(2.0 * N * PI)) / ln_10);
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n <= 1)printf("1\n");
        else printf("%.0lf\n", reback(n));
    }
    return 0;
}

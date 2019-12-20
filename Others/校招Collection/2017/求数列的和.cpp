// https://www.nowcoder.com/practice/02f23a209c0c4d2484e29b560c174de1

#include <cstdio>
#include <cmath>

using namespace std;

int main() {

    int m, i;
    double res, n;

    while (scanf("%lf %d", &n, &m) != EOF) {

        res = 0;
        for (i = 0; i < m; i++) {
            res += n;
            n = sqrt(n);
        }
        printf("%.2lf\n", res);

    }

    return 0;
}
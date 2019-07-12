// https://www.nowcoder.com/practice/fe19f8a78a5148018f4be53ae9b5e11e

#include <cmath>
#include <iostream>

using namespace std;

int main() {

    long double n;
    int m;
    while (cin >> n >> m) {
        long double s = n;
        for (int i = 0; i < m - 1; ++i) {
            n = sqrt(n);
            s += n;
        }
        printf("%.2Lf\n", s);
    }

    return 0;
}
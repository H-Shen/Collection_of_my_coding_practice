// https://www.nowcoder.com/practice/0e3301735881444d902834df9b13a74c

#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    int m, n;
    double H, s;
    cin >> m;
    while (m--) {
        cin >> H >> n;
        s = H;
        for (int i = 0; i < n; ++i) {
            H /= 2.0;
            s += 2 * H;
        }
        s -= 2 * H;
        printf("%.2lf\n", s);
    }
    return 0;
}
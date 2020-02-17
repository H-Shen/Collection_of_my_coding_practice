#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int actual_D, actual_M, actual_Y;
    cin >> actual_D >> actual_M >> actual_Y;
    int expect_D, expect_M, expect_Y;
    cin >> expect_D >> expect_M >> expect_Y;
    if (actual_Y > expect_Y) {
        cout << 10000 << endl;
    } else if (actual_Y < expect_Y) {
        cout << 0 << endl;
    } else if (actual_M > expect_M) {
        cout << 500 *(actual_M - expect_M) << endl;
    } else if (actual_D > expect_D) {
        cout << 15 *(actual_D - expect_D) << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}

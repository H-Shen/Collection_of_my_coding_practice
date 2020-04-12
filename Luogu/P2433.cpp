#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int T;
    cin >> T;
    if (T == 1) {
        cout << "I love Luogu!";
    } else if (T == 2) {
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
        cout << 3 << endl;
        cout << 12 << endl;
        cout << 2 << endl;
    } else if (T == 4) {
        printf("%.3lf\n", 500.0 / 3);
    } else if (T == 5) {
        cout << 15 << endl;
    } else if (T == 6) {
        cout << sqrt((36 + 81) * 1.0) << endl;
    } else if (T == 7) {
        cout << 110 << endl;
        cout << 90 << endl;
        cout << 0 << endl;
    } else if (T == 8) {
        cout << 2 * 5 * 3.141593 << endl;
        cout << 3.141593 * 5 * 5 << endl;
        cout << 4 * 3.141593 * 5 * 5 * 5 / 3 << endl;
    } else if (T == 9) {
        cout << 22 << endl;
    } else if (T == 10) {
        cout << 9 << endl;
    } else if (T == 11) {
        cout << 100 * 1.0 / 3 << endl;
    } else if (T == 12) {
        cout << 13 << endl;
        cout << "R" << endl;
    } else if (T == 13) {
        double pi = 3.141593;
        double v_1 = 4.0 * (pi * 4 * 4 * 4) / 3.0;
        double v_2 = 4.0 * (pi * 10 * 10 * 10) / 3.0;
        double v_3 = v_1 + v_2;
        double a = pow(v_3, 1.0 / 3.0);
        cout << (int) a << endl;
    } else if (T == 14) {
        cout << 50 << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const double CLOCK_TICK = 100.0;

int convert(double a) {
    if (a == (int) a) {
        return (int) a;
    }
    int decimal = (int) (a * 10) % 10;
    if (decimal >= 5) {
        return (int) a + 1;
    }
    return (int) a;
}

string convertS(int n) {
    string res;
    if (n < 10) {
        res = '0' + to_string(n);
    } else {
        res = to_string(n);
    }
    return res;
}

int main() {
    int C1, C2;
    cin >> C1 >> C2;
    double gapDouble = (C2 - C1) / (CLOCK_TICK);
    int gap = convert(gapDouble);

    int h = gap / 3600;
    int m = (gap - 3600 * h) / 60;
    int s = gap - 3600 * h - 60 * m;

    cout << convertS(h) << ":" << convertS(m) << ":" << convertS(s) << endl;

    return 0;
}
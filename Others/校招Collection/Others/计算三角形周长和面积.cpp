// https://www.nowcoder.com/practice/109a44d649a142d483314e8a57e2c710
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    double p, s;
    p = (a + b + c) / 2.0;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("circumference=%.2lf area=%.2lf\n", p * 2.0, s);
    return 0;
}
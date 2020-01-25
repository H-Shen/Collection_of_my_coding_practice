// https://open.kattis.com/problems/tetration
//
#include <bits/extc++.h>

using namespace std;

int main() {

    long double y;
    scanf("%Lf", &y);
    printf("%.6Lf\n", pow(y, static_cast<long double>(1.0) / y));

    return 0;
}

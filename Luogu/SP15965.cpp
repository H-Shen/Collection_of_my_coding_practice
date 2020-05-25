#include <cstdio>

using namespace std;
using ll = long long;

long long gcd(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return gcd(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return gcd(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    long long t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Least Common Multiple
long long lcm(long long a, long long b) {

    // Case 1:
    if (a < 0) {
        return lcm(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return lcm(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    return a / gcd(a, b) * b;
}

int main() {

    int t;
    ll a, b, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &a, &b);
        c = lcm(a, b);
        printf("%lld %lld\n", c / a, c / b);
    }

    return 0;
}
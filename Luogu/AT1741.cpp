#include <cstdio>

using namespace std;

int my_gcd(int m, int n) {
    if (m == 0) return n;
    if (n == 0) return m;
    return my_gcd(n, m % n);
}

int my_lcm(int m, int n) {
    return m * n / my_gcd(m, n);
}

int main() {

    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    int temp = my_lcm(a, b);
    int ans = temp;
    while (ans < n) {
        ans += temp;
    }
    printf("%d\n", ans);


    return 0;
}

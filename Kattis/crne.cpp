// https://open.kattis.com/problems/crne
//
#include <bits/extc++.h>

using namespace std;
using ull = unsigned long long;

int main() {

    // input
    ull N;
    scanf("%llu", &N);
    if (N % 2 == 0) {
        ull a = N / 2;
        printf("%llu\n", (1 + a) * (1 + a));
    } else {
        ull a = (N - 1) / 2;
        printf("%llu\n", (1 + a) * (2 + a));
    }

    return 0;
}

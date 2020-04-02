#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 1000005;
int f[MAXN];  // f[i] = the number of divisors of i

void pre() {
    for(int i = 1; i < MAXN; ++i) {
        for (int j = 1; i * j < MAXN; ++j) {
            ++f[i * j];
        }
    }
}

int main() {
    pre();
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += f[i];
    }
    printf("%d\n", sum);
    return 0;
}
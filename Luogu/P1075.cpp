#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 44723;
int is_prime[MAXN];

bool check(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void pre() {
    for (int i = 2; i <= MAXN; ++i) {
        if(check(i)) {
            is_prime[i] = 1;
        }
    }
}

int main() {

    pre();
    int n;
    scanf("%d", &n);
    int left = static_cast<int>(sqrt(n * 1.0)) + 1;
    int right;
    for (int i = left; i >= 2; --i) {
        right = n / i;
        if (n % i == 0 && is_prime[i]) {
            printf("%d\n", max(i, right));
            break;
        }
    }

    return 0;
}
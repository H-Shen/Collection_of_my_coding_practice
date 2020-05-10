#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    if (n % 2 == 0 && n != 2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
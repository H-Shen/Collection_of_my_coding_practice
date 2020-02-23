#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    // n*(n-1)*(n-2)*(n-3)/24
    int temp;
    scanf("%d", &temp);
    __int128 n = temp;
    long long p = n*(n-1)*(n-2)*(n-3)/24;
    printf("%lld\n", p);
    return 0;
}

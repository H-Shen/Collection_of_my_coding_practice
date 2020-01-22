#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    printf("%d\n", sum);

    return 0;
}
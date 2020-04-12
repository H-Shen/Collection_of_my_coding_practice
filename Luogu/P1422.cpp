#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    double s;
    scanf("%d", &n);
    if (n <= 150) {
        s = n * 0.4463;
    } else if (n <= 400) {
        s = (n - 150) * 0.4663 + 150 * 0.4463;
    } else {
        s = (n - 400) * 0.5663 + 150 * 0.4463 + 250 * 0.4663;
    }
    printf("%.1f\n", s);

    return 0;
}
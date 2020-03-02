#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    scanf("%d", &n);
    int maxVal = 0;
    int current = 1;
    int last;
    int val;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        if (i == 0) {
            last = val;
        } else if (val - last == 1) {
            ++current;
            last = val;
        } else {
            maxVal = max(maxVal, current);
            current = 1;
            last = val;
        }
    }
    maxVal = max(maxVal, current);
    printf("%d\n", maxVal);

    return 0;
}

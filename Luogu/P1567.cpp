#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, val;
    scanf("%d", &n);
    int counter = 0;
    int last = -1;
    int max_val = -1;
    while (n--) {
        scanf("%d", &val);
        if (last == -1) {
            last = val;
            ++counter;
        } else if (val > last) {
            last = val;
            ++counter;
        } else {
            last = val;
            max_val = max(max_val, counter);
            counter = 1;
        }
    }
    max_val = max(max_val, counter);
    printf("%d\n", max_val);
    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, val;
    scanf("%d", &n);
    bool first_item = true;
    int counter = 0;
    int maxVal = numeric_limits<int>::min();
    int minVal = numeric_limits<int>::max();
    while (n--) {
        scanf("%d", &val);
        if (first_item) {
            first_item = false;
            maxVal = max(maxVal, val);
            minVal = min(minVal, val);
        } else {
            if (maxVal < val) {
                maxVal = val;
                ++counter;
            }
            if (minVal > val) {
                minVal = val;
                ++counter;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}


#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, val;
    scanf("%d", &n);
    array<int, 3> A{};
    for (int i = 0, counter = 0; i < n; ++i, ++counter) {
        scanf("%d", &val);
        if (counter == 3) {
            counter = 0;
        }
        A.at(counter) += val;
    }
    int maxVal = *max_element(A.begin(), A.end());
    if (A.at(0) == maxVal) {
        printf("chest\n");
    } else if (A.at(1) == maxVal) {
        printf("biceps\n");
    } else {
        printf("back\n");
    }

    return 0;
}


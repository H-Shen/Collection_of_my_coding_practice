#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (counter < 10) {
                printf("0%d", counter);
            } else {
                printf("%d", counter);
            }
            ++counter;
        }
        printf("\n");
    }
    printf("\n");
    counter = 1;
    int empty_slots;
    int non_empty_slots;
    for (int i = 0; i < n; ++i) {
        empty_slots = n - i - 1;
        for (int j = 0; j < empty_slots; ++j) {
            printf("  ");
        }
        non_empty_slots = n - empty_slots;
        for (int j = 0; j < non_empty_slots; ++j) {
            if (counter < 10) {
                printf("0%d", counter);
            } else {
                printf("%d", counter);
            }
            ++counter;
        }
        printf("\n");
    }

    return 0;
}


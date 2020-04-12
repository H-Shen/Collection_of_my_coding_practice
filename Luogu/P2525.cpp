#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    if (prev_permutation(A.begin(), A.end())) {
        bool first_item = true;
        for (const auto &i : A) {
            if (first_item) {
                first_item = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    } else {
        printf("ERROR");
    }
    printf("\n");

    return 0;
}
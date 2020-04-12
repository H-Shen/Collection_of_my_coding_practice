#include <bits/extc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    iota(A.begin(), A.end(), 1);
    do {
        for (int i = 0; i < n; ++i) {
            printf("%5d", A.at(i));
        }
        printf("\n");
    } while (next_permutation(A.begin(), A.end()));

    return 0;
}
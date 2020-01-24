#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    
    int n, m, val;
    scanf("%d %d", &n, &m);
    vector<int> A(n + 1);
    for (int i = 0;i < m; ++i) {
        scanf("%d", &val);
        ++A[val];
    }
    bool firstItem = true;
    int length = static_cast<int>(A.size());
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < A.at(i); ++j) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}
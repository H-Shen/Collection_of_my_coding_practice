#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &A.at(i));
    }
    vector<int> B(n);
    for (int i = 0; i < n; ++i) {
        int counter = 0;
        try {
            for (int j = i - 1;; --j) {
                if (A.at(j) < A.at(i)) {
                    ++counter;
                }
            }
        } catch (...) {

        }
        B.at(i) = counter;
    }
    bool firstItem = true;
    for (const auto &i : B) {
        if (firstItem) {
            firstItem = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");

    return 0;
}


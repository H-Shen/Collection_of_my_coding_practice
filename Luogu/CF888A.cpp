#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int counter = 0;
    if (n > 2) {
        for (int i = 1; i < n - 1; ++i) {
            if (A.at(i) > A.at(i - 1) && A.at(i) > A.at(i + 1)) {
                ++counter;
            }
            if (A.at(i) < A.at(i - 1) && A.at(i) < A.at(i + 1)) {
                ++counter;
            }
        }
    }
    printf("%d\n", counter);
    return 0;
}
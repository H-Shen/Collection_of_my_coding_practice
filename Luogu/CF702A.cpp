#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int startIndex = 0;
    int endIndex = 0;
    int maxLength = 1;
    for (int i = 1; i < n; ++i) {
        if (A.at(i) > A.at(i - 1)) {
            endIndex = i;
        } else {
            maxLength = max(maxLength, endIndex - startIndex + 1);
            startIndex = i;
            endIndex = i;
        }
    }
    maxLength = max(maxLength, endIndex - startIndex + 1);

    printf("%d\n", maxLength);

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) scanf("%d", &i);
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    int length = static_cast<int>(A.size());
    for (int i = 2; i < length; ++i) {
        if (A.at(i) - A.at(i - 1) == 1 && A.at(i - 1) - A.at(i - 2) == 1) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
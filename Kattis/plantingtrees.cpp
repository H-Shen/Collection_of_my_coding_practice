// https://open.kattis.com/problems/plantingtrees
//

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(static_cast<size_t>(n));
    for (auto &i : A) {
        scanf("%d", &i);
        ++i;
    }
    sort(A.begin(), A.end(),  greater<>());
    int counter = 0;
    int maxVal = -1;
    for (const auto &i : A) {
        maxVal = max(maxVal, counter + i);
        ++counter;
    }
    printf("%d\n", maxVal + 1);

    return 0;
}

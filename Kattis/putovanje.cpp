// https://open.kattis.com/problems/putovanje
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, c;
    scanf("%d %d", &n, &c);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int maxVal = -1;
    int counter;
    int weight;
    for (int i = 0; i < n; ++i) {
        weight = 0;
        counter = 0;
        for (int j = i; j < n; ++j) {
            if (weight + A.at(j) > c) {
                continue;
            } else {
                weight += A.at(j);
                ++counter;
            }
        }
        maxVal = max(maxVal, counter);
    }
    printf("%d\n", maxVal);

    return 0;
}

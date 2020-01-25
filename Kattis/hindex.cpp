// https://open.kattis.com/problems/hindex
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    sort(A.begin(), A.end(), greater<>());
    int a, b;
    int minVal = numeric_limits<int>::max();
    int hIndex = numeric_limits<int>::min();
    for (int i = 0; i < n; ++i) {
        minVal = min(A.at(i), minVal);
        a = i + 1;
        b = minVal;
        if (b > a) {
            b = a;
        } else {
            a = b;
        }
        hIndex = max(hIndex, a);
    }
    printf("%d\n", hIndex);


    return 0;
}

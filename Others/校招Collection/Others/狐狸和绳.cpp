// write your code here cpp
// https://www.nowcoder.com/practice/41d40d1b2a82471f81900cce4320bd3b

#include <bits/stdc++.h>

using namespace std;

vector<int> A;

int main() {
    int n, i;
    while (~scanf("%d", &n)) {
        A.resize(static_cast<unsigned long>(n));
        for (i = 0; i < n; i++) {
            scanf("%d", &A[i]);
        }
        sort(A.begin(), A.end());

        int maxVal = -1;
        int crn;
        for (i = 0; i < n; i++) {
            crn = A[i] * (n - i);
            if (crn > maxVal) {
                maxVal = crn;
            }
        }

        printf("%d\n", maxVal);
        vector<int>().swap(A);
    }
    return 0;
}
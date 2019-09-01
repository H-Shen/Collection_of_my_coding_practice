// https://open.kattis.com/problems/owlandfox
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100000;
unordered_map<int, vector<int> > A;

inline static
int sumOfDigits(int n) {
    int result = 0;
    while (n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result;
}

int main() {

    for (int i = 0; i <= MAXN; ++i) {
        A[sumOfDigits(i)].emplace_back(i);
    }
    int t, n, maxVal;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        const auto &p = A[sumOfDigits(n) - 1];
        maxVal = -1;
        for (const auto &element : p) {
            if (element < n) {
                maxVal = max(maxVal, element);
            }
        }
        printf("%d\n", maxVal);
    }

    return 0;
}

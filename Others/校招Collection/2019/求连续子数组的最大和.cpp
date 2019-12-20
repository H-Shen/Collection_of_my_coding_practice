// https://www.nowcoder.com/practice/8705437354604a7cb9ba7bf959e42de6

#include <bits/stdc++.h>

using namespace std;

inline static
int maxSubArray(const vector<int> &A) {

    if (A.empty()) {
        return numeric_limits<int>::min();
    }

    int currentSum = 0, maxSum = 0, interval = A[0];
    int n = static_cast<int>(A.size());
    for (int i = 0; i < n; i++) {
        currentSum += A[i];

        if (A[i] <= 0 && A[i] > interval) {
            interval = A[i];
        }

        if (currentSum > maxSum)
            maxSum = currentSum;
        else if (currentSum < 0)
            currentSum = 0;
    }

    if (maxSum <= 0)
        return 0;
    return maxSum;
}

int main() {

    ios_base::sync_with_stdio(false);
    vector<int> A;
    int val;
    char ch;
    cin >> val;
    A.emplace_back(val);
    while (cin >> ch) {
        cin >> val;
        A.emplace_back(val);
    }

    cout << maxSubArray(A) << endl;

    return 0;
}
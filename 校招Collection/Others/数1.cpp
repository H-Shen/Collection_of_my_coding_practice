// https://ac.nowcoder.com/acm/problem/14511

#include <bits/stdc++.h>

using namespace std;

int NumberOf1Between1AndN_Solution(int n) {
    int ccount = 0;
    int Factor = 1;
    int LowerNum = 0;
    int CurrNum = 0;
    int HigherNum = 0;
    if (n <= 0) {
        return 0;
    }
    while (n / Factor != 0) {
        LowerNum = n - (n / Factor) * Factor;
        CurrNum = (n / Factor) % 10;
        HigherNum = n / (Factor * 10);
        if (CurrNum == 0) {
            ccount += HigherNum * Factor;
        } else if (CurrNum == 1) {
            ccount += HigherNum * Factor + LowerNum + 1;
        } else {
            ccount += (HigherNum + 1) * Factor;
        }
        Factor *= 10;
    }
    return ccount;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n)
        cout << NumberOf1Between1AndN_Solution(n) << endl;
    return 0;
}
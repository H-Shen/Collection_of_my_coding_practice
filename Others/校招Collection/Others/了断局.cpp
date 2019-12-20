// https://ac.nowcoder.com/acm/problem/15036

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main()
{
    vector <ll> A = { 0, 1, 1, 2, 4, 7, 13, 24, 44, 81 };
    while (A.size() <= 50) {
        A.push_back(A[A.size() - 1] + A[A.size() - 2] + A[A.size() - 3]);
    }
    int n;
    while (cin >> n) {
        cout << A[n - 1] << endl;
    }
    return 0;
}
// https://ac.nowcoder.com/acm/problem/14714

#include <iostream>
#include <vector>

using namespace std;
const int maxn = 25;
using ll = long long;

int main()
{
    vector <ll> A = { 2,3 };
    while (A.size() != maxn) {
        A.push_back(A[A.size() - 1] + A[A.size() - 2]);
    }
    int n;
    cin >> n;
    cout << A[n - 1] << endl;
    return 0;
}
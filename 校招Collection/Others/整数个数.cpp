// https://ac.nowcoder.com/acm/problem/14516

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &p : A) {
        cin >> p;
    }
    cout << count(A.begin(), A.end(), 1) << ' ' <<
            count(A.begin(), A.end(), 5) << ' ' <<
            count(A.begin(), A.end(), 10) << endl;
    return 0;
}
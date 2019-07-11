// https://open.kattis.com/problems/cetiri
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 3;

int main()
{
    vector <int> A(maxn);
    for (auto &&i : A)
    {
        cin >> i;
    }
    sort(A.begin(), A.end());

    int a = A[0];
    int b = A[1];
    int c = A[2];
    int gap = 0;

    if (2 * b == a + c)
    {
        gap = c - b;
        cout << c + gap << endl;
    }
    else if (3 * b == 2 * a + c)
    {
        gap = b - a;
        cout << c - gap << endl;
    }
    else
    {
        gap = c - b;
        cout << b - gap << endl;
    }


    return 0;
}

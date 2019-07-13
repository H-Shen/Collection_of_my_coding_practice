// https://open.kattis.com/problems/mjehuric
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 5;

inline
void printArr(const vector <int> A)
{
    for (int i = 0; i < maxn - 1; ++i)
    {
        cout << A[i] << ' ';
    }
    cout << A[maxn - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    vector <int> A(maxn);
    vector <int> ans {1, 2, 3, 4, 5};

    for (auto &&i : A)
    {
        cin >> i;
    }

    while (1)
    {
        if (A == ans)
        {
            break;
        }
        if (A[0] > A[1])
        {
            swap(A[0], A[1]);
            printArr(A);
        }
        if (A[1] > A[2])
        {
            swap(A[1], A[2]);
            printArr(A);
        }
        if (A[2] > A[3])
        {
            swap(A[2], A[3]);
            printArr(A);
        }
        if (A[3] > A[4])
        {
            swap(A[3], A[4]);
            printArr(A);
        }
    }

    return 0;
}

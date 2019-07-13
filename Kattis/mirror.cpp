// https://open.kattis.com/problems/mirror
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, r, c;
    cin >> t;
    for (int kase = 1; kase <= t; ++kase)
    {
        cin >> r >> c;
        vector <string> A(r);
        for (auto &&i : A)
        {
            cin >> i;
        }
        cout << "Test " << kase << endl;
        for (int i = r - 1; i >= 0; --i)
        {
            cout << string(A[i].rbegin(), A[i].rend()) << endl;
        }
    }
    return 0;
}

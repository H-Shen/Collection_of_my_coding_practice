// https://open.kattis.com/problems/permutedarithmeticsequence

#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

inline
bool judge(const vector <int> &a)
{
    if (a.size() <= 2)
    {
        return true;
    }
    int diff = a[1] - a[0];
    for (size_t i = 2; i < a.size(); ++i)
    {
        if (a[i] - a[i - 1] != diff)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        vector <int> A(m);
        for (auto &&i : A)
        {
            cin >> i;
        }

        vector <int> A_copy(A);
        sort(A_copy.begin(), A_copy.end());

        if (judge(A))
        {
            cout << "arithmetic" << endl;
        }
        else if (A != A_copy && judge(A_copy))
        {
            cout << "permuted arithmetic" << endl;
        }
        else
        {
            cout << "non-arithmetic" << endl;
        }
    }

    return 0;
}

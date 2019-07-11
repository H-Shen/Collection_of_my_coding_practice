// https://open.kattis.com/problems/compoundwords
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string s, tmp;
    unordered_set <string> A;
    while (cin >> s)
    {
        A.insert(s);
    }
    unordered_set <string> A_compound;
    for (auto it = A.begin(); it != A.end(); ++it)
    {
        for (auto it1 = A.begin(); it1 != A.end(); ++it1)
        {
            if ((*it1) != (*it))
            {
                tmp = (*it1) + (*it);
                A_compound.insert(tmp);
            }
        }
    }

    vector <string> ans(A_compound.size());
    size_t pos = 0;
    for (auto it = A_compound.begin(); it != A_compound.end(); ++it)
    {
        ans[pos++] = *it;
    }
    sort(ans.begin(), ans.end());
    for (const auto &i : ans)
    {
        cout << i << endl;
    }
    return 0;
}

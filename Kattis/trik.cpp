// https://open.kattis.com/problems/trik

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    vector <int> L = {1, 0, 0};
    string s;
    cin >> s;

    for (const auto &i : s)
    {
        switch (i)
        {
            case 'A':
                swap(L[0], L[1]);
                break;
            case 'B':
                swap(L[1], L[2]);
                break;
            case 'C':
                swap(L[0], L[2]);
                break;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        if (L[i] == 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}

// https://open.kattis.com/problems/permutationencryption

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, len;
    string s;
    string split = "";

    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector <int> A(n);
        for (auto &&i : A)
        {
            cin >> i;
            --i;
        }

        getchar();
        getline(cin, s);
        split = "";
        len = s.size();

        int i;
        int substr_len;
        vector <string> B;
        for (i = 0; i < len; i += n)
        {
            split = s.substr(i, n);
            B.push_back(s.substr(i, n));
        }
        try {
            split = s.substr(i);
            if (split != "")
            {
                B.push_back(s.substr(i, n));
            }
        } catch(...)
        {}

        for (size_t idx = 0; idx < B.size(); ++idx)
        {
            substr_len = B[idx].size();
            if (substr_len < n)
            {
                B[idx] = B[idx] + string(n - substr_len, ' ');
            }
        }

        string trans = "";
        cout << "\'";
        for (size_t idx = 0; idx < B.size(); ++idx)
        {
            trans = "";
            for (int idxx = 0; idxx < n; ++idxx)
            {
                trans = trans + B[idx][A[idxx]];
            }
            cout << trans;
        }
        cout << "\'";
        cout << endl;

    }

    return 0;
}

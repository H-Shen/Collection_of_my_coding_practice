#include <string>
#include <iostream>
#include <cctype>

// https://ac.nowcoder.com/acm/problem/15971
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    char tmp;
    while (cin >> s)
    {
        for (const auto &ch : s)
        {
            if (isupper(ch))
            {
                tmp = tolower(ch);
                cout << tmp;
            }
            else if (islower(ch))
            {
                tmp = toupper(ch);
                cout << tmp;
            }
            else
            {
                cout << ch;
            }
        }
        cout << endl;
    }

    return 0;
}
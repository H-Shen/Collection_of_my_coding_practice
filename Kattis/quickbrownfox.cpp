// https://open.kattis.com/problems/quickbrownfox
#include <iostream>
#include <cstdio>
#include <cctype>
#include <functional>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, s);
        unordered_set <char> A;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (const auto &i : s)
        {
            if (isalpha(i))
            {
                A.insert(i);
            }
        }
        string res;
        for (char i = 'a'; i <= 'z'; ++i)
        {
            if (A.find(i) == A.end())
            {
                res = res + i;
            }
        }
        if (res == "")
        {
            cout << "pangram" << endl;
        }
        else
        {
            cout << "missing " << res << endl;
        }
    }
    return 0;
}

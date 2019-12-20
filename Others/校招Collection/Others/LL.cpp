#include <iostream>
// https://ac.nowcoder.com/acm/problem/15545

#include <string>
#include <cctype>

using namespace std;
string a = "lovelive";

int main()
{
    string s;
    while (getline(cin, s))
    {
        for (auto && i : s)
        {
            if (isupper(i))
            {
                i = tolower(i);
            }
        }
        if (s == a)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }

    return 0;
}
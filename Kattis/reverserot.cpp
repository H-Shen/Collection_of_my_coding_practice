// https://open.kattis.com/problems/reverserot

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    string s;
    while (1)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }
        cin >> s;
        for (auto &&i : s)
        {
            for (size_t j = 0; j < a.size(); ++j)
            {
                if (i == a[j])
                {
                    i = a[j + n];
                    break;
                }
            }
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}

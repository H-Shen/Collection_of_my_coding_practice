// https://open.kattis.com/problems/divideby100
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

void handlePrint(const string &s)
{
    int len = s.size();
    int i = 0;
    for (i = 0; i < len; ++i)
    {
        if (s[i] != '0')
        {
            break;
        }
    }
    int j = 0;
    for (j = len - 1; j >= 0; --j)
    {
        if (s[j] != '0')
        {
            break;
        }
    }
    //output
    if (s[i] == '.')
    {
        cout << "0.";
        ++i;
    }
    if (s[j] == '.')
    {
        --j;
    }
    for (; i <= j; ++i)
    {
        cout << s[i];
    }
    cout << endl;
}

string handle(const string &s)
{
    string res;
    int len = s.size();
    int i = 0;
    for (i = 0; i < len; ++i)
    {
        if (s[i] != '0')
        {
            break;
        }
    }
    if (s[i] == '.')
    {
        res = res + "0.";
        ++i;
    }

    int j = 0;
    for (j = len - 1; j >= 0; --j)
    {
        if (s[j] != '0')
        {
            break;
        }
    }
    if (s[j] == '.')
    {
        --j;
    }
    for (; i <= j; ++i)
    {
        res = res + s[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    string n, m, res;

    cin >> n >> m;
    if (n.size() == m.size())
    {
        if (n == m)
        {
            res = "1";
        }
        else
        {
            res = n[0] + string(".") + n.substr(1);
        }
    }
    else if (n.size() > m.size())
    {
        res = n.substr(0, n.size() - m.size() + 1) + string(".") + n.substr(n.size() - m.size() + 1);
    }
    else
    {
        if (m.size() == n.size() + 1)
        {
            res = "0." + n;
        }
        else
        {
            res = "0." + string(m.size() - n.size() - 1, '0') + n;
        }
    }
    handlePrint(res);
    return 0;
}

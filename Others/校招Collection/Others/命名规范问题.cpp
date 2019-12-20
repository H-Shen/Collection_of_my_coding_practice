// https://ac.nowcoder.com/acm/problem/15740

#include <bits/stdc++.h>

using namespace std;
const int maxn = 25;
char s[maxn];

bool handler(vector <string> &filter, const string &s)
{
    string tmp;
    bool haveAns = true;

    for (const auto &i : s)
    {
        if (!haveAns)
        {
            break;
        }
        if (isupper(i) && tmp != "")
        {
            if (tmp.size() < 2)
            {
                haveAns = false;
                break;
            }
            filter.push_back(tmp);
            tmp = i;
        }
        else
        {
            tmp = tmp + i;
        }
    }
    if (tmp != "")
    {
        if (tmp.size() < 2)
        {
            haveAns = false;
        }
        filter.push_back(tmp);
    }
    if (filter.size() < 2)
    {
        haveAns = false;
    }

    return haveAns;
}

string convert(const vector <string> &filter)
{
    string res;
    char tmp = '\0';
    for (size_t i = 0; i < filter.size(); ++i)
    {
        for (size_t j = 0; j < filter[i].size(); ++j)
        {
            if (isupper(filter[i][j]))
            {
                tmp = tolower(filter[i][j]);
                res = res + tmp;
            }
            else
            {
                res = res + filter[i][j];
            }
        }
        if (i < filter.size() - 1)
        {
            res = res + '_';
        }
    }
    return res;
}

int main()
{
    int n;
    string str;
    vector <string> filter;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        str = s;
        vector <string>().swap(filter);
        if (handler(filter, str))
        {
            printf("%s\n", convert(filter).c_str());
        }
        else
        {
            printf("%s\n", s);
        }
    }
    return 0;
}
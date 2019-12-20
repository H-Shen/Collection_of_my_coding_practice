// https://ac.nowcoder.com/acm/problem/15546

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addTailZero(const string &s, const int &maxLen)
{
    int len = static_cast<int>(s.size());
    string res = s;
    if (maxLen > len)
    {
        res = string(maxLen - len, '0') + s;
    }
    return res;
}

string cleanTailZero(const string &s)
{
    string res;
    bool tailZero = true;
    for (const auto &i : s)
    {
        if (i == '0' && tailZero)
        {
            continue;
        }
        else if (i != '0' && tailZero)
        {
            res += i;
            tailZero = false;
        }
        else if (!tailZero)
        {
            res += i;
        }
    }
    if (res == "")
    {
        res = "0";
    }
    return res;
}

string add(const string &A, const string &B)
{
    int len = A.size();
    string sum(len, '0');
    for (int i = 0; i < len; ++i)
    {
        sum[i] = (A[i] - '0' + B[i] - '0') % 10 + '0';
    }
    return sum;
}

int main()
{
    string A, B, res;
    int maxLen;
    while (cin >> A >> B)
    {
        maxLen = max(A.size(), B.size());
        A = addTailZero(A, maxLen);
        B = addTailZero(B, maxLen);
        res = cleanTailZero(add(A, B));
        cout << res << endl;
    }
    return 0;
}
#include <string>
#include <cstdio>

using namespace std;

const int maxn = 17580, maxChar = 150;
string A[maxn];
char cstr[maxChar];

int main()
{
    //pre
    string s = "aaa";
    int cnt = 0;
    for (; s[0] <= 'z'; ++s[0])
    {
        for (; s[1] <= 'z'; ++s[1])
        {
            for (; s[2] <= 'z'; ++s[2])
            {
                A[cnt++] = s;
            }
            s[2] = 'a';
        }
        s[1] = 'a';
    }

    int T, length, pos;
    string str, res;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %s", &length, cstr);
        res = "";
        str = cstr;
        pos = 0;
        while (pos != length)
        {
            res = res + A[stoi(str.substr(pos, 5))];
            pos += 5;
        }
        printf("%s\n", res.c_str());
    }

    return 0;
}
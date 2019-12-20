// https://ac.nowcoder.com/acm/problem/15680

#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 25;
char s[MAXN], sub[MAXN];

bool includeJudge(unordered_map <char, int> &s_, unordered_map <char, int> &sub_)
{
    for (auto & it : sub_)
    {
        if (s_.find(it.first) == s_.end() )
        {
            return false;
        }
        else if (s_[it.first] < it.second )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, i, maxLen;
    while (~scanf("%s", s))
    {
        unordered_map <char, int> s_count;
        for (i = 0; s[i] != '\0'; ++i)
        {
            ++s_count[s[i]];
        }
        scanf("%d", &n);
        maxLen = -1;
        while (n--)
        {
            unordered_map <char, int> sub_count;
            scanf("%s", sub);
            for (i = 0; sub[i] != '\0'; ++i)
            {
                ++sub_count[sub[i]];
            }
            if (includeJudge(s_count, sub_count))
            {
                maxLen = max(maxLen, i);
            }
        }

        if (maxLen != -1)
            printf("%d\n", maxLen);
        else
            printf("0\n");
    }
    return 0;
}
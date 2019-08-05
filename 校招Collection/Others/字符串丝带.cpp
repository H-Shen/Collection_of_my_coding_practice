https://ac.nowcoder.com/acm/problem/17363#include <cstring>
#include <cstdio>
#include <vector>
#include <unordered_map>

using namespace std;
const int maxn = 1000005;
char s[maxn];
int ans[maxn];

int main()
{
    int len, query;
    scanf("%d %d", &len, &query);
    getchar();
    scanf("%s", s);

    unordered_map <char, int> cnt;

    for (int i = 0; i < len; ++i)
    {
        ++cnt[s[i]];
        ans[i] = cnt[s[i]];
    }

    int pos;
    for (int i = 0; i < query; ++i)
    {
        scanf("%d", &pos);
        printf("%d\n", ans[pos - 1]);
    }

    return 0;
}
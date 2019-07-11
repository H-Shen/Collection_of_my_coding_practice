// https://open.kattis.com/problems/cd
#include <cstdio>
#include <unordered_set>

using namespace std;
unordered_set <int> A;

int main()
{
    int n, m, pos, cnt;
    while (1)
    {
        cnt = 0;
        A.clear();
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &pos);
            A.insert(pos);
        }
        for (int i = 0; i < m; ++i)
        {
            scanf("%d", &pos);
            if (A.find(pos) != A.end()) ++cnt;
        }
        printf("%d\n", cnt);
    }

    return 0;
}

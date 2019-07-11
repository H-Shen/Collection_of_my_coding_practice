// https://open.kattis.com/problems/batterup
#include <cstdio>

using namespace std;

int main()
{
    int n, val;
    scanf("%d", &n);
    int sum = 0;
    int cnt = 0;
    while (n--)
    {
        scanf("%d", &val);
        if (val != -1)
        {
            sum += val;
            ++cnt;
        }
    }
    printf("%.3lf\n", sum * 1.0 / cnt);
    return 0;
}

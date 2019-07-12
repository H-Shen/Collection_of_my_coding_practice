// https://open.kattis.com/problems/grassseed
#include <cstdio>

using namespace std;

int main()
{
    double c, w, l;
    scanf("%lf", &c);
    int n;
    scanf("%d", &n);
    double s = 0.0;
    while (n--)
    {
        scanf("%lf %lf", &w, &l);
        s = s + w * l * c;
    }
    printf("%.7lf\n", s);
    return 0;
}

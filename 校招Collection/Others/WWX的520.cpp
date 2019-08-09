// https://ac.nowcoder.com/acm/problem/15894

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 35;
char s[MAXN];

struct Present
{
    string name;
    int price;
};

bool cmp(const Present &a, const Present &b)
{
    if (a.price == b.price)
    {
        return (a.name > b.name);
    }
    return (a.price > b.price);
}

int main()
{
    int T, N, k, kase;
    scanf("%d", &T);
    for (kase = 1; kase <= T; ++kase)
    {
        scanf("%d", &N);
        vector <Present> A(N);
        for (auto &&i : A)
        {
            scanf("%s %d", s, &i.price);
            i.name = s;
        }
        scanf("%d", &k);
        sort(A.begin(), A.end(), cmp);
        printf("#%d: %s %d\n", kase, A[k - 1].name.c_str(), A[k - 1].price);
    }
    return 0;
}
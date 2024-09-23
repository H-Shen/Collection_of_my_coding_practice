// https://ac.nowcoder.com/acm/problem/15750

#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-5;
const int maxn = 15;
const int NOIP2017_FULL = 600;
const int SDOI2018_FULL = 300;

char s[maxn];

inline
bool cmpDouble(const double &a, const double &b)
{
    return (abs(a - b) <= eps);
}

struct Person
{
    string name;
    int NOIP2017;
    int SDOI2018_0;
    int SDOI2018_1;
    int SDOI2018_2;
    int SDOI2018_3;
    double total = 0;
};

double cal(const int &score, const int &maxScore, const int &fullScore)
{
    return static_cast<double>(score * fullScore) / static_cast<double>(maxScore);
}

bool cmp(const Person &a, const Person &b)
{
    if (cmpDouble(a.total, b.total))
    {
        return (a.name < b.name);
    }
    return (a.total > b.total);
}

int main()
{
    int n;
    int maxScore2017;
    int maxScore2018_0;
    int maxScore2018_1;
    int maxScore2018_2;
    int maxScore2018_3;

    while (~scanf("%d", &n))
    {
        maxScore2017 = -1;
        maxScore2018_0 = -1;
        maxScore2018_1 = -1;
        maxScore2018_2 = -1;
        maxScore2018_3 = -1;

        vector <Person> A(n);
        for (auto &&i : A)
        {
            scanf("%s %d %d %d %d %d", s, &i.NOIP2017, &i.SDOI2018_0, &i.SDOI2018_1,
                 &i.SDOI2018_2, &i.SDOI2018_3);
            i.name = s;
            maxScore2017   = max(maxScore2017, i.NOIP2017);
            maxScore2018_0 = max(maxScore2018_0, i.SDOI2018_0);
            maxScore2018_1 = max(maxScore2018_1, i.SDOI2018_1);
            maxScore2018_2 = max(maxScore2018_2, i.SDOI2018_2);
            maxScore2018_3 = max(maxScore2018_3, i.SDOI2018_3);
        }

        for (auto &&i : A)
        {
            i.total = 0.25 *  cal(i.NOIP2017, maxScore2017, NOIP2017_FULL) +
                      0.25 * (cal(i.SDOI2018_0, maxScore2018_0, SDOI2018_FULL) +
                              cal(i.SDOI2018_1, maxScore2018_1, SDOI2018_FULL))+
                      0.5  * (cal(i.SDOI2018_2, maxScore2018_2, SDOI2018_FULL) +
                              cal(i.SDOI2018_3, maxScore2018_3, SDOI2018_FULL));
        }

        sort(A.begin(), A.end(), cmp);
        for (const auto &i : A)
        {
            printf("%s %.5lf\n", i.name.c_str(), i.total);
        }
    }

    return 0;
}

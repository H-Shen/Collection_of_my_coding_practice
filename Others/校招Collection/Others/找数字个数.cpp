#include <vector>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
constexpr int N = 1000;

int main()
{
    int n, a, b, i, cnt;
    string str_a, str_b, str_c, tmp;
    vector <char> intersec;

    scanf("%d", &n);
    while (n--) {
        cnt = 0;
        scanf("%d %d", &a, &b);
        str_a = to_string(a);
        str_b = to_string(b);
        str_c = str_a + str_b;
        set <char> A(str_c.begin(), str_c.end());
        for (i = 1; i <= N; ++i) {
            tmp = to_string(i);
            set <char> B(tmp.begin(), tmp.end());
            vector <char>().swap(intersec);
            set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(intersec));
            if (i % a == 0 || i % b == 0 || intersec.size() != 0) {
                ++cnt;
            }
        }
        printf("%d\n", N - cnt);
    }

    return 0;
}
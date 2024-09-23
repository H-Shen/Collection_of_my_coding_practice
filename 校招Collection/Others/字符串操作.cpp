// https://ac.nowcoder.com/acm/problem/14895

#include <bits/stdc++.h>

using namespace std;

constexpr int maxn = 110;
char s[maxn];

int main()
{
    int n, m, l, r, len;
    char c1, c2;
    scanf("%d %d", &n, &m);
    scanf("%s", s);
    string str = s;
    len = str.size();

    while (m--) {
        scanf("%d %d %c %c", &l, &r, &c1, &c2);
        if (l > len) {
            l = len;
        }
        if (r > len) {
            r = len;
        }
        if (l <= 0) {
            l = 1;
        }
        if (r <= 0) {
            r = 1;
        }
        replace_if(str.begin() + l - 1, str.begin() + r, [&](const char &c){return c == c1;}, c2);
    }
    printf("%s\n", str.c_str());

    return 0;
}
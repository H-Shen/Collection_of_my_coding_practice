#include <bits/stdc++.h>

using namespace std;
const int MAXN = 4, N = 10;
char s[N];

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    int i, j;
    string res;

    for (i = 0; i < n; ++i) {
        for (j = 0; j < MAXN; ++j) {
            scanf("%s", s);
            if (s[2] == 'T') {
                res.append(to_string(s[0] - 'A' + 1));
            }
        }
    }
    printf("%s\n", res.c_str());
    return 0;
}
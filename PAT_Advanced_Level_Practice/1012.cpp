#include <bits/stdc++.h>


using namespace std;

const char c[] = "ACME";
int a[2002][4];
int have[102];
map<string, int> id;
char s[10000];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d", s, &a[i][1], &a[i][2], &a[i][3]);
        a[i][0] = (a[i][1] + a[i][2] + a[i][3]) / 3;
        id[s] = i;
    }
    for (int i = 0; i < 4; ++i) {
        memset(have, 0, sizeof(have));
        for (int j = 0; j < n; ++j) {
            ++have[a[j][i]];
        }
        for (int j = 100; j >= 0; --j) {
            have[j] += have[j + 1];
        }
        for (int j = 0; j < n; ++j) {
            a[j][i] = have[a[j][i] + 1] + 1;
        }
    }
    for (; m; --m) {
        scanf("%s", s);
        auto t = id.find(s);
        if (t == id.end()) {
            printf("N/A\n");
        } else {
            int x = 0;
            for (int i = 0; i < 4; ++i) {
                if (a[t->second][i] < a[t->second][x]) {
                    x = i;
                }
            }
            printf("%d %c\n", a[t->second][x], c[x]);
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25;
char name[MAXN];
char partial[MAXN];
unordered_map<string, int> A;

int main()
{
    int n;
    scanf("%d", &n);
    string s;
    while (n--) {
        scanf("%s %s", name, partial);
        s = partial;
        if (strcmp(name, "add") == 0) {
            for (size_t i = 0; i <= s.size(); ++i) {
                ++A[s.substr(0, i)];
            }
        } else {
            if (A.find(s) != A.end()) {
                printf("%d\n", A[s]);
            } else {
                printf("0\n");
            }
        }
    }

    return 0;
}

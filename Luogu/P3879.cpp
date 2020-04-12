#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 30;
char s[MAXN];
unordered_map<string, set<int> >A;

int main() {

    int t, n;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        scanf("%d", &n);
        while (n--) {
            scanf("%s", s);
            A[s].insert(i);
        }
    }
    scanf("%d", &t);
    string str;
    while (t--) {
        scanf("%s", s);
        str = s;
        if (A.find(s) != A.end()) {
            bool first_item = true;
            for (const auto &i : A[s]) {
                if (first_item) {
                    first_item = false;
                } else {
                    printf(" ");
                }
                printf("%d", i);
            }
        }
        printf("\n");
    }

    return 0;
}
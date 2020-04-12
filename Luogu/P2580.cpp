#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 60;
char s[MAXN];

int main() {

    int n;
    scanf("%d", &n);
    unordered_set<string> A;
    while (n--) {
        scanf("%s", s);
        A.insert(s);
    }
    int m;
    scanf("%d", &m);
    unordered_set<string> B;
    while (m--) {
        scanf("%s", s);
        if (A.find(s) == A.end()) {
            printf("WRONG\n");
        } else if (B.find(s) != B.end()) {
            printf("REPEAT\n");
        } else {
            B.insert(s);
            printf("OK\n");
        }
    }

    return 0;
}
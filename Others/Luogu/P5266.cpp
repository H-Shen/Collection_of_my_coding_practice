#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 30;
char s[MAXN];

unordered_map<string, int> A;

int main() {

    int n, op, score;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &op);
        switch (op) {
            case 1:
                scanf("%s %d", s, &score);
                A[s] = score;
                printf("OK\n");
                break;
            case 2:
                scanf("%s", s);
                if (A.find(s) != A.end()) {
                    printf("%d\n", A[s]);
                } else {
                    printf("Not found\n");
                }
                break;
            case 3:
                scanf("%s", s);
                if (A.find(s) != A.end()) {
                    A.erase(s);
                    printf("Deleted successfully\n");
                } else {
                    printf("Not found\n");
                }
                break;
            default:
                printf("%d\n", static_cast<int>(A.size()));
                break;
        }
    }

    return 0;
}
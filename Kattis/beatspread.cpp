// https://open.kattis.com/problems/beatspread
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int n, A, B;
    bool hasAns;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &A, &B);
        hasAns = false;
        for (int s = 0; s <= A; ++s) {
            int d = A - s;
            if (abs(s - d) == B) {
                if (s < d) {
                    swap(s, d);
                }
                printf("%d %d\n", s, d);
                hasAns = true;
                break;
            }
        }
        if (!hasAns) {
            printf("impossible\n");
        }
    }


    return 0;
}

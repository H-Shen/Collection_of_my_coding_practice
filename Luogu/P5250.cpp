#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int n;
    int length;
    int op;
    scanf("%d", &n);
    set<int> A;
    while (n--) {
        scanf("%d %d", &op, &length);
        if (op == 1) {
            if (A.find(length) != A.end()) {
                printf("Already Exist\n");
            } else {
                A.insert(length);
            }
        } else {
            if (A.empty()) {
                printf("Empty\n");
            } else if (A.find(length) != A.end()) {
                printf("%d\n", length);
                A.erase(length);
            } else {
                if (length < *A.begin()) {
                    int temp = *A.begin();
                    printf("%d\n", temp);
                    A.erase(temp);
                } else if (length > *A.rbegin()) {
                    int temp = *A.rbegin();
                    printf("%d\n", temp);
                    A.erase(temp);
                } else {
                    auto iter = A.lower_bound(length);
                    int a = *iter;
                    int b = *(--iter);
                    int gap_a = abs(a - length);
                    int gap_b = abs(b - length);
                    if (gap_a == gap_b) {
                        printf("%d\n", b);
                        A.erase(b);
                    } else if (gap_a > gap_b) {
                        printf("%d\n", b);
                        A.erase(b);
                    } else {
                        printf("%d\n", a);
                        A.erase(a);
                    }
                }
            }
        }
    }
    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tmp;
    scanf("%d", &n);
    set<int> A;
    int len = 0;

    while (n--) {
        scanf("%d", &tmp);
        if (tmp > 0) {
            A.insert(tmp);
        }
    }
    len = A.size();

    vector<int> A_vec(A.begin(), A.end());

    if (len == 0) {
        printf("1\n");
        return 0;
    }

    if (A_vec.front() != 1) {
        printf("1\n");
        return 0;
    } else {
        for (int i = 1; i < len; ++i) {
            if (A_vec[i] - A_vec[i - 1] != 1) {
                printf("%d\n", A_vec[i - 1] + 1);
                return 0;
            }
        }
    }
    printf("%d\n", A_vec.back() + 1);
    return 0;

}
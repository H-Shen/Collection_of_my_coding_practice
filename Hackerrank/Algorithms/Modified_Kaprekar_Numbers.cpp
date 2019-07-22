#include <cstdio>
#include <vector>

using namespace std;

const vector<int> A{1, 9, 45, 55, 99, 297, 703, 999, 2223, 2728, 4950, 5050,
                    7272, 7777, 9999, 17344, 22222, 77778, 82656, 95121,
                    99999, 142857};

int main() {

    int len = static_cast<int>(A.size());
    vector<int> ans;
    int i, p, q;
    int ans_len = 0;
    scanf("%d %d", &p, &q);
    bool haveAns = false;

    for (i = 0; i < len; i++) {
        if (A[i] >= p && A[i] <= q) {
            ans.push_back(A[i]);
            ans_len++;
            haveAns = true;
        } else if (A[i] > q)
            break;
    }
    if (!haveAns)
        printf("INVALID RANGE\n");
    else {
        for (i = 0; i < ans_len - 1; i++) {
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[ans_len - 1]);
    }

    return 0;
}

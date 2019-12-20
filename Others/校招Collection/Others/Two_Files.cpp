// https://ac.nowcoder.com/acm/problem/14330

#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set <int> A;
unordered_set <int> B;

int main()
{
    int n, i, tmp;
    bool haveAns = true;

    while (~scanf("%d", &n)) {

        A.clear();
        B.clear();
        haveAns = true;

        for (i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            A.insert(tmp);
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &tmp);
            if (!haveAns) {
                continue;
            }
            if (A.find(tmp) == A.end()) {
                haveAns = false;
            } else {
                B.insert(tmp);
            }
        }
        if (!haveAns || (haveAns && A.size() != B.size())) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
    return 0;
}
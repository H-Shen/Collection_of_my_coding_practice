// https://ac.nowcoder.com/acm/problem/15203

#include <bits/stdc++.h>

using namespace std;
unordered_map<int, int> A;
vector<int> res;
using pairType = decltype(A)::value_type;

int main() {
    int T, i, n, j, id, cnt;
    scanf("%d", &T);
    for (i = 0; i < T; ++i) {

        scanf("%d", &n);

        A.clear();
        vector<int>().swap(res);
        cnt = 0;

        for (j = 0; j < n; ++j) {
            scanf("%d", &id);
            ++A[id];
        }
        auto myMax = max_element(A.begin(), A.end(), [](const pairType &a, const pairType &b) {
            return (a.second < b.second);
        });

        res.resize(A.size());
        for (auto it : A) {
            if (it.second == myMax->second) {
                res[cnt++] = it.first;
            }
        }

        if (cnt == static_cast<int>(A.size())) {
            printf("-1\n");
        } else {
            res.resize(cnt);
            sort(res.begin(), res.end());
            printf("%d\n", cnt);
            for (j = 0; j < cnt - 1; ++j) {
                printf("%d ", res[j]);
            }
            printf("%d\n", res[cnt - 1]);
        }

    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N;
    scanf("%d %d", &N, &M);
    vector<int> score(M);
    vector<int> answer(M);
    for (auto &i : score) {
        scanf("%d", &i);
    }
    for (auto &i : answer) {
        scanf("%d", &i);
    }
    int i, j, sum, tmp;
    for (i = 0; i < N; ++i) {
        sum = 0;
        for (j = 0; j < M; ++j) {
            scanf("%d", &tmp);
            if (tmp == answer[j]) {
                sum += score[j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
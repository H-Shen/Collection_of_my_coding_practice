// https://www.nowcoder.com/practice/f7c80167c5b04fd2ac4b6d7080a73f01

#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;

struct Stu {
    string id;
    int score = 0;
    bool canRank = false;
};

bool cmp(const Stu &x, const Stu &y) {
    if (x.score == y.score)
        return (x.id < y.id);
    return (x.score > y.score);
}

int main() {

    int N, M, G, i, j;
    scanf("%d %d %d", &N, &M, &G);
    vector<int> fullScoreList(static_cast<unsigned long>(M));
    for (i = 0; i < M; i++) {
        scanf("%d", &fullScoreList[i]);
    }

    int higherOrEqualThanG = 0;
    int total, issueId;
    vector<Stu> userList(static_cast<unsigned long>(N));

    for (i = 0; i < N; i++) {

        char temp[maxn];
        total = 0;
        scanf("%s %d", temp, &total);
        userList[i].id = temp;

        for (j = 0; j < total; j++) {
            scanf("%d", &issueId);
            userList[i].score += fullScoreList[issueId - 1];
        }

        if (userList[i].score >= G) {
            higherOrEqualThanG++;
            userList[i].canRank = true;
        }

    }

    sort(userList.begin(), userList.end(), cmp);
    printf("%d\n", higherOrEqualThanG);
    for (i = 0; i < N; i++) {
        if (userList[i].canRank)
            printf("%s %d\n", userList[i].id.c_str(), userList[i].score);
    }

    return 0;
}
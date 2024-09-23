#include <bits/stdc++.h>

using namespace std;

constexpr int MAXCHAR = 20;
char s[MAXCHAR];

struct Stu {
    string email;
    int score;
    int rank;
};

bool cmp(const Stu &a, const Stu &b) {
    if (a.score == b.score) {
        return (a.email < b.email);
    }
    return (a.score > b.score);
}

int main() {

    int N, G, K;
    scanf("%d %d %d", &N, &G, &K);
    vector<Stu> A(N);
    for (auto &&r : A) {
        scanf("%s %d", s, &r.score);
        r.email = s;
    }
    sort(A.begin(), A.end(), cmp);

    A.front().rank = 1;
    int currentRank = A.front().rank;

    for (int i = 1; i < N; ++i) {
        if (A[i].score == A[i - 1].score) {
            A[i].rank = currentRank;
        } else {
            A[i].rank = i + 1;
            currentRank = A[i].rank;
        }
    }

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        if (A[i].score >= G) {
            sum += 50;
        } else if (A[i].score >= 60) {
            sum += 20;
        }
    }
    printf("%d\n", sum);

    for (int i = 0; i < N; ++i) {
        if (A[i].rank <= K) {
            printf("%d %s %d\n", A[i].rank, A[i].email.c_str(), A[i].score);
        }
    }


    return 0;

}

#include <bits/stdc++.h>


using namespace std;
const int MAXN = 10;
char s0[MAXN], s1[MAXN];

struct Stu {
    string id;
    string name;
    int score;
};

bool cmp1(const Stu &A, const Stu &B) {
    return (A.id < B.id);
}

bool cmp2(const Stu &A, const Stu &B) {
    if (A.name == B.name) {
        return (A.id < B.id);
    }
    return (A.name < B.name);
}

bool cmp3(const Stu &A, const Stu &B) {
    if (A.score == B.score) {
        return (A.id < B.id);
    }
    return (A.score < B.score);
}

int main() {

    int n, c, i;
    scanf("%d %d", &n, &c);
    getchar();
    vector<Stu> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%s %s %d", s0, s1, &A[i].score);
        A[i].id = s0;
        A[i].name = s1;
    }

    switch (c) {
        case 1 :
            sort(A.begin(), A.end(), cmp1);
            break;
        case 2:
            sort(A.begin(), A.end(), cmp2);
            break;
        case 3:
            sort(A.begin(), A.end(), cmp3);
            break;
        default:
            break;
    }

    for (const auto &p : A) {
        printf("%s %s %d\n", p.id.c_str(), p.name.c_str(), p.score);
    }

    return 0;
}

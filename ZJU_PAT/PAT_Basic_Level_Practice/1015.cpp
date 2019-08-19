#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
char s[maxn];

struct Stu {
    string id;
    int D;
    int C;
    int S;
};

bool cmp(const Stu &a, const Stu &b) {
    if (a.S == b.S) {
        if (a.D == b.D) {
            return (a.id < b.id);
        }
        return (a.D > b.D);
    }
    return (a.S > b.S);
}

int main() {
    int N, L, H, tmpD, tmpC;
    scanf("%d %d %d", &N, &L, &H);
    int cnt = 0;

    vector<Stu> A, B, C, D;
    while (N--) {
        scanf("%s %d %d", s, &tmpD, &tmpC);
        if (tmpD >= L && tmpC >= L) {
            Stu tmpStu;
            tmpStu.id = s;
            tmpStu.C = tmpC;
            tmpStu.D = tmpD;
            tmpStu.S = tmpC + tmpD;
            if (tmpD >= H && tmpC >= H) {
                A.push_back(tmpStu);
                ++cnt;
            } else if (tmpD >= H && tmpC < H) {
                B.push_back(tmpStu);
                ++cnt;
            } else if (tmpD < H && tmpC < H && tmpD >= tmpC) {
                C.push_back(tmpStu);
                ++cnt;
            } else {
                D.push_back(tmpStu);
                ++cnt;
            }
        }
    }

    sort(A.begin(), A.end(), cmp);
    sort(B.begin(), B.end(), cmp);
    sort(C.begin(), C.end(), cmp);
    sort(D.begin(), D.end(), cmp);

    printf("%d\n", cnt);
    for_each(A.begin(), A.end(), [](const Stu &i) { printf("%s %d %d\n", i.id.c_str(), i.D, i.C); });
    for_each(B.begin(), B.end(), [](const Stu &i) { printf("%s %d %d\n", i.id.c_str(), i.D, i.C); });
    for_each(C.begin(), C.end(), [](const Stu &i) { printf("%s %d %d\n", i.id.c_str(), i.D, i.C); });
    for_each(D.begin(), D.end(), [](const Stu &i) { printf("%s %d %d\n", i.id.c_str(), i.D, i.C); });

    return 0;
}
#include <bits/stdc++.h>


using namespace std;

const int MAXN = 3;

struct id {
    int num1;
    int num2;
    int num3;
    int num4;
};

bool cmp(id x, id y) {

    if (x.num4 == y.num4) {
        if (x.num2 == y.num2)
            return x.num1 > y.num1;
        return x.num2 < y.num2;
    }
    return x.num4 < y.num4;
}

int main() {

    int N, L, H, M, i, j, len;
    scanf("%d %d %d", &N, &L, &H);
    vector<struct id> a, b, c, d;
    M = 0;

    for (i = 0; i < N; i++) {
        vector<int> s(MAXN);
        scanf("%d %d %d", &s[0], &s[1], &s[2]);
        if (s[1] >= L && s[2] >= L) {
            if (s[1] >= H && s[2] >= H) {
                id temp;
                temp.num1 = s[0];
                temp.num2 = s[1];
                temp.num3 = s[2];
                temp.num4 = s[1] + s[2];
                a.push_back(temp);
            } else if (L <= s[2] && s[2] < H && s[1] >= H) {
                id temp;
                temp.num1 = s[0];
                temp.num2 = s[1];
                temp.num3 = s[2];
                temp.num4 = s[1] + s[2];
                b.push_back(temp);
            } else if (L <= s[2] && s[2] < H && L <= s[1] && s[1] < H && s[1] >= s[2]) {
                id temp;
                temp.num1 = s[0];
                temp.num2 = s[1];
                temp.num3 = s[2];
                temp.num4 = s[1] + s[2];
                c.push_back(temp);
            } else {
                id temp;
                temp.num1 = s[0];
                temp.num2 = s[1];
                temp.num3 = s[2];
                temp.num4 = s[1] + s[2];
                d.push_back(temp);
            }
            M++;
        }
    }

    sort(a.begin(), a.end(), cmp);
    reverse(a.begin(), a.end());
    sort(b.begin(), b.end(), cmp);
    reverse(b.begin(), b.end());
    sort(c.begin(), c.end(), cmp);
    reverse(c.begin(), c.end());
    sort(d.begin(), d.end(), cmp);
    reverse(d.begin(), d.end());
    vector<id> total;
    total.insert(total.end(), a.begin(), a.end());
    total.insert(total.end(), b.begin(), b.end());
    total.insert(total.end(), c.begin(), c.end());
    total.insert(total.end(), d.begin(), d.end());

    len = total.size();
    printf("%d\n", M);
    for (j = 0; j < len; j++) {
        printf("%d %d %d\n", total[j].num1, total[j].num2, total[j].num3);
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 20;
char s[MAXN];

struct Stu {
    string name;
    int height;
};

bool cmp(const struct Stu &a, const struct Stu &b) {
    if (a.height == b.height) {
        return (a.name > b.name);
    }
    return (a.height < b.height);
}

deque<Stu> change(const deque<Stu> &A) {
    deque<Stu> res;
    bool changeBool = true;
    for (auto it = A.crbegin(); it != A.crend(); ++it) {
        if (changeBool) {
            res.push_back(*it);
            changeBool = false;
        } else {
            res.push_front(*it);
            changeBool = true;
        }
    }
    return res;
}

int main() {
    int n, k, i, j;
    scanf("%d %d", &n, &k);
    vector<Stu> A(n);
    for (i = 0; i < n; ++i) {
        scanf("%s %d", s, &A[i].height);
        A[i].name = s;
    }
    sort(A.begin(), A.end(), cmp);
    int cnt = n / k;

    vector<deque<Stu> > res;
    int pos = 0;

    for (i = 0; i < k - 1; ++i) {
        deque<Stu> tmp;
        for (j = 0; j < cnt; ++j) {
            tmp.push_back(A[pos]);
            ++pos;
        }
        tmp = change(tmp);
        res.push_back(tmp);
    }

    deque<Stu> tmp;
    for (; pos < n; ++pos) {
        tmp.push_back(A[pos]);
    }
    tmp = change(tmp);
    res.push_back(tmp);

    reverse(res.begin(), res.end());

    for (i = 0; i < (int) res.size(); ++i) {
        for (j = 0; j < (int) res[i].size() - 1; ++j) {
            printf("%s ", res[i][j].name.c_str());
        }
        printf("%s\n", res[i][res[i].size() - 1].name.c_str());
    }
    return 0;
}
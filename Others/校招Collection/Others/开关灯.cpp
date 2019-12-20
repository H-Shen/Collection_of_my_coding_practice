// https://ac.nowcoder.com/acm/problem/16743

#include <bits/stdc++.h>

using namespace std;

struct Timestamp {
    int a, b, c, d;
};

struct Log {
    int x;
    int y;
    int status;
    Timestamp time;
};

bool cmp(const Log &a, const Log &b) {
    if (a.time.a == b.time.a) {
        if (a.time.b == b.time.b) {
            if (a.time.c == b.time.c) {
                return (a.time.d < b.time.d);
            }
            return (a.time.c < b.time.c);
        }
        return (a.time.b < b.time.b);
    }
    return (a.time.a < b.time.a);
}

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<vector<int> > A(n, vector<int>(m));
    vector<Log> Table(k);
    vector<int> countSave(k);

    for (auto &&i : Table) {
        scanf("%d %d %d %d:%d:%d.%d", &i.x, &i.y, &i.status, &i.time.a, &i.time.b, &i.time.c, &i.time.d);
        --i.x;
        --i.y;
    }

    sort(Table.begin(), Table.end(), cmp);

    int currentCount = 0;
    int pos = 0;

    for (const auto &i : Table) {
        if (i.status == 1) {
            --A[i.x][i.y];
            if (A[i.x][i.y] == 0) {
                --currentCount;
            }
        } else {
            if (A[i.x][i.y] == 0) {
                ++currentCount;
            }
            ++A[i.x][i.y];
        }
        countSave[pos++] = currentCount;
    }

    int maxCount = *max_element(countSave.begin(), countSave.end());
    int maxCountLastPos = 0;
    for (int i = 0; i < k; ++i) {
        if (countSave[i] == maxCount) {
            maxCountLastPos = i;
        }
    }

    vector<vector<int> > A_copy(n, vector<int>(m));
    for (int i = 0; i <= maxCountLastPos; ++i) {
        if (Table[i].status == 1) {
            --A_copy[Table[i].x][Table[i].y];
        } else {
            ++A_copy[Table[i].x][Table[i].y];
        }
    }

    for (const auto &i : A_copy) {
        for (const auto &j : i) {
            if (j == 0) {
                printf("0");
            } else {
                printf("1");
            }
        }
        printf("\n");
    }

    return 0;
}
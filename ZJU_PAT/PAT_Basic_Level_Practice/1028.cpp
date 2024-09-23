#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
char s[maxn], s0[maxn];

struct Id {
    string s;
    string dateString;
    int y{};
    int m{};
    int d{};
};

bool validate(int y, int m, int d) {
    if (y > 2014 || (y == 2014 && m > 9) || (y == 2014 && m == 9 && d > 6))
        return false;
    return !(y < 1814 || (y == 1814 && m < 9) || (y == 1814 && m == 9 && d < 6));
}


bool cmp(const Id &a, const Id &b) {
    if (a.y == b.y) {
        if (a.m == b.m) {
            return (a.d < b.d);
        } else {
            return (a.m < b.m);
        }
    } else {
        return (a.y < b.y);
    }
}

int main() {
    int n, y, m, d;
    scanf("%d", &n);
    vector<Id> A;
    while (n--) {
        scanf("%s %s", s, s0);
        sscanf(s0, "%d/%d/%d", &y, &m, &d);
        if (!validate(y, m, d)) {
            continue;
        }
        Id tmp;
        tmp.s = s;
        tmp.dateString = s0;
        tmp.y = y;
        tmp.m = m;
        tmp.d = d;
        A.emplace_back(tmp);
    }
    if (A.empty()) {
        printf("0\n");
    } else {
        auto it = minmax_element(A.begin(), A.end(), cmp);
        printf("%lu %s %s\n", A.size(), it.first->s.c_str(),
               it.second->s.c_str());
    }
    return 0;
}
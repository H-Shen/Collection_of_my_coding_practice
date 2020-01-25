// https://open.kattis.com/problems/busyschedule
//
#include <bits/extc++.h>

using namespace std;

char s[20];
char s_[10];

struct Date {
    string str;
    int h;
    int m;
    bool isAM;
};

bool cmp(Date lhs, Date rhs) {
    if (lhs.isAM && !rhs.isAM) {
        return true;
    }
    if (!lhs.isAM && rhs.isAM) {
        return false;
    }
    if (lhs.h == 12) {
        lhs.h = 0;
    }
    if (rhs.h == 12) {
        rhs.h = 0;
    }
    if (lhs.h == rhs.h) {
        return (lhs.m < rhs.m);
    }
    return (lhs.h < rhs.h);
}

int main() {

    int n;
    Date d;
    bool firstItem = true;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        if (firstItem) {
            firstItem = false;
        } else {
            printf("\n");
        }
        getchar();
        vector<Date> A(n);
        for (auto &i : A) {
            scanf("%[^\n]", s);
            d.str = s;
            sscanf(s, "%d:%d %s", &d.h, &d.m, s_);
            d.isAM = strcmp(s_, "p.m.") != 0;
            i = d;
            getchar();
        }
        sort(A.begin(), A.end(), cmp);
        for (const auto &i : A) {
            printf("%s\n", i.str.c_str());
        }
    }

    return 0;
}

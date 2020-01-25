// https://open.kattis.com/problems/pachydermpeanutpacking
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 10;
constexpr double EPS = 1e-6;

char cstr[MAXN];

inline static
int sgn(const double &a) {
    if (a > EPS) {
        return 1;
    }
    if (a > -EPS) {
        return 0;
    }
    return -1;
}

struct Box {
    double x1, x2, y1, y2;
    string type;
};

int main() {

    int n, m;
    double x, y;
    bool firstItem = true;
    bool inTheBox;
    string type;

    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<Box> A(n);
        for (auto &i : A) {
            scanf("%lf %lf %lf %lf %s", &i.x1, &i.y1, &i.x2, &i.y2, cstr);
            i.type = cstr;
        }
        scanf("%d", &m);
        if (firstItem) {
            firstItem = false;
        } else {
            if (m > 0) {
                printf("\n");
            }
        }
        while (m--) {
            scanf("%lf %lf %s", &x, &y, cstr);
            type = cstr;
            inTheBox = false;
            for (const auto &i : A) {
                if (sgn(x - i.x1) >= 0 && sgn(x - i.x2) <= 0 && sgn(y - i.y1) >= 0 && sgn(y - i.y2) <= 0) {
                    printf("%s ", cstr);
                    if (type == i.type) {
                        printf("correct\n");
                    } else {
                        printf("%s\n", i.type.c_str());
                    }
                    inTheBox = true;
                    break;
                }
            }
            if (!inTheBox) {
                printf("%s floor\n", cstr);
            }
        }
    }

    return 0;
}

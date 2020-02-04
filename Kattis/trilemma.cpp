// https://open.kattis.com/problems/trilemma
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// Ax + By + C = 0
struct Line {
    int A, B, C;

    Line(const pair<int, int> &a, const pair<int, int> &b) {
        A = a.second - b.second;
        B = b.first - a.first;
        C = a.first * b.second - b.first * a.second;
    }

    bool onLine(const pair<int, int> &p) {
        return A * p.first + B * p.second + C == 0;
    }
};

inline static
string solve(int x1, int y1, int x2, int y2, int x3, int y3) {
    if (x1 == x2 && y1 == y2) {
        return "not a triangle";
    }
    if (x1 == x3 && y1 == y3) {
        return "not a triangle";
    }
    if (x2 == x3 && y2 == y3) {
        return "not a triangle";
    }
    if (Line line(make_pair(x1, y1), make_pair(x2, y2)); line.onLine(
            make_pair(x3, y3))) {
        return "not a triangle";
    }
    int a_2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    int b_2 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    int c_2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    int temp0;
    int temp1;
    int temp2;
    // isosceles
    if (a_2 == b_2 || a_2 == c_2 || b_2 == c_2) {
        temp0 = a_2 + b_2 - c_2;
        temp1 = a_2 + c_2 - b_2;
        temp2 = b_2 + c_2 - a_2;
        if (temp0 == 0 || temp1 == 0 || temp2 == 0) {
            return "isosceles right triangle";
        }
        if (temp0 < 0 || temp1 < 0 || temp2 < 0) {
            return "isosceles obtuse triangle";
        }
        return "isosceles acute triangle";
    }
        // scalene
    else {
        temp0 = a_2 + b_2 - c_2;
        temp1 = a_2 + c_2 - b_2;
        temp2 = b_2 + c_2 - a_2;
        if (temp0 == 0 || temp1 == 0 || temp2 == 0) {
            return "scalene right triangle";
        }
        if (temp0 < 0 || temp1 < 0 || temp2 < 0) {
            return "scalene obtuse triangle";
        }
        return "scalene acute triangle";
    }
}


int main() {

    int n, x1, y1, x2, y2, x3, y3;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
        printf("Case #%d: %s\n", i, solve(x1, y1, x2, y2, x3, y3).c_str());
    }

    return 0;
}

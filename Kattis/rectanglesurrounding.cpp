// https://open.kattis.com/problems/rectanglesurrounding
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 503;

struct Point {
    int x, y;
};

int main() {

    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        vector<pair<Point, Point> > A(n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &A.at(i).first.x, &A.at(i).first.y, &A.at(i).second.x, &A.at(i).second.y);
        }
        vector<vector<int> > K(MAXN, vector<int>(MAXN, 0));
        for (int i = 0; i < n; ++i) {
            for (int x = A.at(i).first.x; x < A.at(i).second.x; ++x) {
                for (int y = A.at(i).first.y; y < A.at(i).second.y; ++y) {
                    ++K.at(x).at(y);
                }
            }
        }
        int counter = 0;
        for (const auto &i : K) {
            for (const auto &j : i) {
                if (j != 0) {
                    ++counter;
                }
            }
        }
        printf("%d\n", counter);
    }

    return 0;
}

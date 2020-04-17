// https://open.kattis.com/problems/appallingarchitecture
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int h, w;
    scanf("%d %d", &h, &w);
    getchar_unlocked();
    vector<vector<char> > A(h, vector<char>(w));
    for (auto &i : A) {
        for (auto &j : i) {
            scanf("%c", &j);
        }
        getchar_unlocked();
    }
    int x_sum = 0;
    int counter = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (A.at(i).at(j) != '.') {
                x_sum += (j + 1);
                ++counter;
            }
        }
    }
    int x_left_most = -1;
    for (int j = 0; j < w; ++j) {
        if (A.back().at(j) != '.') {
            x_left_most = (j + 1);
            break;
        }
    }
    int x_right_most = -1;
    for (int j = w - 1; j >= 0; --j) {
        if (A.back().at(j) != '.') {
            x_right_most = (j + 1);
            break;
        }
    }
    int x_center = static_cast<int>(lround(x_sum * 1.0 / counter));
    if (x_center < x_left_most) {
        printf("left\n");
    } else if (x_center > x_right_most > 0) {
        printf("right\n");
    } else {
        printf("balanced\n");
    }

    return 0;
}

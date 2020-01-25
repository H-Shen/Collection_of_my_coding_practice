// https://open.kattis.com/problems/mathhomework
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int b, d, c, l;
    scanf("%d %d %d %d", &b, &d, &c, &l);
    vector<tuple<int, int, int> > A;
    int i_max = l / b;
    int j_max = l / d;
    int k_max = l / c;
    for (int i = 0; i <= i_max; ++i) {
        for (int j = 0; j <= j_max; ++j) {
            for (int k = 0; k <= k_max; ++k) {
                if ( i * b + j * d + k * c == l ) {
                    A.emplace_back(make_tuple(i, j, k));
                }
            }
        }
    }
    if (A.empty()) {
        printf("impossible\n");
    } else {
        for (const auto &it : A) {
            printf("%d %d %d\n", get<0>(it), get<1>(it), get<2>(it));
        }
    }
    return 0;
}

// https://open.kattis.com/problems/dartscores
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

vector<int> r_list = {20, 40, 60, 80, 100, 120, 140, 160, 180, 200};

int main() {

    int T, n, x, y, score, dist;
    int length = static_cast<int>(r_list.size());
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        score = 0;
        while (n--) {
            scanf("%d %d", &x, &y);
            dist = x*x + y*y;
            for (int i = 0; i < length; ++i) {
                if (dist <= r_list.at(i) * r_list.at(i)) {
                    score += (10 - i);
                    break;
                }
            }
        }
        printf("%d\n", score);
    }

    return 0;
}

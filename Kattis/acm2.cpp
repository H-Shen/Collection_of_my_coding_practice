// https://open.kattis.com/problems/acm2
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAX_TIME = 300;

int main() {

    int n, p, val;
    scanf("%d %d", &n, &p);
    vector<int> A;
    int num_ac = 0;
    int penalty_time = 0;
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        if (i == p) {
            counter += val;
            if (counter > MAX_TIME) {
                break;
            } else {
                ++num_ac;
                penalty_time += counter;
            }
        } else {
            A.emplace_back(val);
        }
    }
    sort(A.begin(), A.end());

    for (const auto &i : A) {
        counter += i;
        if (counter > MAX_TIME) {
            break;
        } else {
            ++num_ac;
            penalty_time += counter;
        }
    }
    printf("%d %d\n", num_ac, penalty_time);

    return 0;
}

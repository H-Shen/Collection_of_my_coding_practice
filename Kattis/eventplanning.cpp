// https://open.kattis.com/problems/eventplanning
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Hotel {
    int price;
    vector<int> schedule;
};

int main() {

    int n, b, h, w;
    scanf("%d %d %d %d", &n, &b, &h, &w);
    vector<Hotel> A(h);
    for (auto &i : A) {
        scanf("%d", &i.price);
        i.schedule.resize(w);
        for (auto &j : i.schedule) {
            scanf("%d", &j);
        }
    }
    bool have_ans = false;
    int min_cost = b;
    int cost;
    for (int i = 0; i < w; ++i) {
        for (const Hotel &H : A) {
            cost = n * H.price;
            if (H.schedule.at(i) >= n && cost <= b) {
                have_ans = true;
                min_cost = min(min_cost, cost);
            }
        }
    }
    if (have_ans) {
        printf("%d\n", min_cost);
    } else {
        printf("stay home\n");
    }

    return 0;
}

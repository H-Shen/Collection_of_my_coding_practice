#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;

inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

struct Item {
    double price;
    int m;
    int v;
};

bool cmp(Item a, Item b){
    return sgn(a.price - b.price) > 0;
}

int main() {
    int n, t, m, v;
    scanf("%d %d", &n, &t);
    vector<Item> K(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &m, &v);
        K.at(i).v = v;
        K.at(i).m = m;
        K.at(i).price = v * 1.0 / m;
    }
    sort(K.begin(), K.end(), cmp);
    int left_m = t;
    double total_v = 0.0;
    for (int i = 0; i < n; ++i) {
        if (left_m >= K.at(i).m) {
            left_m -= K.at(i).m;
            total_v += K.at(i).v * 1.0;
        } else {
            total_v += left_m * 1.0 / K.at(i).m * K.at(i).v;
            break;
        }
    }
    printf("%.2lf\n", total_v);
}
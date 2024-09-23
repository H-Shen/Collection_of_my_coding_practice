#include <bits/stdc++.h>


using namespace std;

const double EPS = 1e-10;

inline int sgn(double a) {
    if (a < -EPS)
        return -1;
    if (a < EPS)
        return 0;
    return 1;
}

struct Mooncake {
    double vol;
    double totalPrice;
    double price;
};

bool cmp(const Mooncake &A, const Mooncake &B) {
    return (sgn(A.price - B.price) > 0);
}

int main() {
    int n, d, i;
    scanf("%d %d", &n, &d);

    vector<Mooncake> mooncake(n);
    for (i = 0; i < n; ++i) {
        scanf("%lf", &mooncake[i].vol);
    }
    for (i = 0; i < n; ++i) {
        scanf("%lf", &mooncake[i].totalPrice);
        mooncake[i].price = mooncake[i].totalPrice / mooncake[i].vol;
    }
    sort(mooncake.begin(), mooncake.end(), cmp);

    double sum = 0.0;
    for (i = 0; i < n; ++i) {

        if (mooncake[i].vol <= d) {
            d -= static_cast<int>(mooncake[i].vol);
            sum += mooncake[i].totalPrice;
        } else {
            sum += d * mooncake[i].totalPrice / mooncake[i].vol;
            break;
        }
        if (d == 0) {
            break;
        }
    }
    printf("%.2lf\n", sum);
    return 0;
}
// https://open.kattis.com/problems/doggopher
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double eps = 1e-7;
inline static
int sgn(const double &x) {
    if (x > eps) {
        return 1;
    }
    if (x > -eps) {
        return 0;
    }
    return -1;
}

struct Node {
    double x, y;
    explicit Node(double x, double y) : x(x), y(y) {}
    Node() = default;
};

double dist(const Node &l, const Node &r) {
    return sqrt( (l.x-r.x)*(l.x-r.x)+(l.y-r.y)*(l.y-r.y) );
}

int main() {

    Node gopher, dog;
    scanf("%lf %lf %lf %lf", &gopher.x, &gopher.y, &dog.x, &dog.y);
    double x, y;
    vector<Node> A;
    while (~scanf("%lf %lf", &x, &y)) {
        A.emplace_back(Node(x, y));
    }
    double dist_gopher, dist_dog;
    for (const Node &i : A) {
        dist_gopher = dist(gopher, i);
        dist_dog = dist(dog, i);
        if (sgn( dist_gopher - dist_dog / 2.0 ) <= 0) {
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", i.x, i.y);
            return 0;
        }
    }
    printf("The gopher cannot escape.\n");
    return 0;
}

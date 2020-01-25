// https://open.kattis.com/problems/carefulascent
//
#include <bits/extc++.h>

using namespace std;

struct Node {
    int lower;
    int upper;
    double factor;

    Node() = delete;

    Node(int lower, int upper, double factor) : lower(lower), upper(upper),
                                                factor(factor) {}
};

int main() {

    int x, y, n, lower, upper;
    double factor;
    scanf("%d %d", &x, &y);
    scanf("%d", &n);
    vector<Node> A;
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %lf", &lower, &upper, &factor);
        A.emplace_back(Node(lower, upper, factor));
    }
    double sum = 0.0;
    for (const auto &[l, u, f] : A) {
        sum += (u - l) * f;
        diff += u - l;
    }
    sum += y - diff;
    printf("%.8lf\n", x * 1.0 / sum);

    return 0;
}

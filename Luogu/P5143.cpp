#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Node {
    int x, y, z;
};

double dist(const Node &l, const Node &r) {
    return sqrt((l.x - r.x) * (l.x - r.x) + (l.y - r.y) * (l.y - r.y) +
                (l.z - r.z) * (l.z - r.z));
}

int main() {

    int n;
    scanf("%d", &n);
    vector<Node> A(n);
    for (auto &i : A) {
        scanf("%d %d %d", &i.x, &i.y, &i.z);
    }
    sort(A.begin(), A.end(), [](const Node &l, const Node &r) {
        return l.z < r.z;
    });
    double sum = 0.0;
    for (int i = 1; i < n; ++i) {
        sum += dist(A.at(i), A.at(i - 1));
    }
    printf("%.3f\n", sum);
    return 0;
}

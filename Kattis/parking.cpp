// https://open.kattis.com/problems/parking
//
#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 105;

int main() {

    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    vector<int> L(MAXN);
    int a, b;
    while (~scanf("%d %d", &a, &b)) {
        for (int i = a; i < b; ++i) {
            ++L.at(i);
        }
    }
    int sum = 0;
    for (const auto &i : L) {
        if (i == 1) {
            sum += A;
        } else if (i == 2) {
            sum += 2 * B;
        } else if (i == 3) {
            sum += 3 * C;
        }
    }
    cout << sum << endl;

    return 0;
}

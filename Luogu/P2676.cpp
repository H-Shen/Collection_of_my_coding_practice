#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n, b;
    scanf("%d %d", &n, &b);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int counter = 0;
    int sum = 0;
    sort(A.begin(), A.end(), greater<>());
    for (const auto &i : A) {
        sum += i;
        ++counter;
        if (sum >= b) {
            break;
        }
    }
    printf("%d\n", counter);
    return 0;
}

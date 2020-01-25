// https://open.kattis.com/problems/server
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int n, t;
    scanf("%d %d", &n, &t);
    vector<int> A(static_cast<int>(n));
    for (auto &i : A) {
        scanf("%d", &i);
    }
    int counter = 0;
    int current_t = 0;
    for (int i = 0; i < n; ++i) {
        current_t += A.at(i);
        if (current_t > t) {
            break;
        }
        ++counter;
    }
    printf("%d\n", counter);

    return 0;
}

// https://open.kattis.com/problems/safepassage
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    scanf("%d", &n);
    deque<int> A(n);
    for (auto &i : A) scanf("%d", &i);
    sort(A.begin(), A.end());

    int a = A.front();
    A.pop_front();
    int b = A.front();
    A.pop_front();
    n -= 2;

    int counter = b;
    for (int i = n - 1;; i -= 2) {
        if (i < 0) {
            break;
        }
        else if (i == 0) {
            counter += a + A.at(0);
            break;
        }
        int case1 = a + A.at(i) + a + A.at(i - 1);
        int case2 = b + A.at(i) + a + b;
        counter += min(case1, case2);
    }
    printf("%d\n", counter);
    return 0;
}

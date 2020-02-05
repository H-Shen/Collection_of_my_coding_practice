// https://open.kattis.com/problems/icpcteamselection
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int dataset, n, s;
    while (~scanf("%d", &dataset)) {
        while (dataset--) {
            scanf("%d", &n);
            deque<int> A(3 * n);
            for (auto &i : A) {
                scanf("%d", &i);
            }
            sort(A.begin(), A.end());
            s = 0;
            while (!A.empty()) {
                A.pop_back();
                s += A.back();
                A.pop_back();
                A.pop_front();
            }
            printf("%d\n", s);
        }
    }

    return 0;
}

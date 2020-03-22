// https://open.kattis.com/problems/transitwoes
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int s, t, n;
    scanf("%d %d %d", &s, &t, &n);
    vector<int> T(n + 1);
    for (auto &i : T) {
        scanf("%d", &i);
    }
    vector<int> B(n);
    for (auto &i : B) {
        scanf("%d", &i);
    }
    vector<int> C(n);
    for (auto &i : C) {
        scanf("%d", &i);
    }
    s += T.front();
    if (n >= 1) {
        for (int i = 1; i <= n; ++i) {
            while (true) {
                if (s % C.at(i - 1) == 0) {
                    break;
                }
                ++s;
            }
            s += B.at(i - 1);
        }
    }
    s += T.back();
    if (s > t) {
        printf("no\n");
    } else {
        printf("yes\n");
    }

    return 0;
}

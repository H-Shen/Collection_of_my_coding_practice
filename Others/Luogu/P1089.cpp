#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 12;
vector<int> A(MAXN);

int main() {

    for (auto &i : A) {
        scanf("%d", &i);
    }
    int residual = 0;
    int store = 0;
    int temp;
    for (int i = 0; i < MAXN; ++i) {
        temp = residual + 300 - A.at(i);
        temp = temp / 100;
        temp = temp * 100;
        if (temp == 0) {
            temp = residual + 300 - A.at(i);
            if (temp < 0) {
                printf("-%d", i + 1);
                return 0;
            } else {
                residual = temp;
            }
        } else {
            store += temp;
            temp = residual + 300 - A.at(i) - temp;
            if (temp < 0) {
                printf("-%d", i + 1);
                return 0;
            } else {
                residual = temp;
            }
        }
    }
    printf("%d\n", (int)(residual + store * 1.2));

    return 0;
}

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int counter;
int n = 1;

void traverse(int &a, int &b, bool up) {
    if (up) {
        for (; a >= 1; --a) {
            ++n;
            if (n == counter) {
                printf("%d/%d\n", a, b);
                exit(0);
            }
            ++b;
        }
    } else {
        for (; b >= 1; --b) {
            ++n;
            if (n == counter) {
                printf("%d/%d\n", a, b);
                exit(0);
            }
            ++a;
        }
    }
}

int main() {

    int a = 1, b = 1;
    scanf("%d", &counter);
    if (counter == 1) {
        printf("%d/%d\n", a, b);
        return 0;
    }

    ++b;
    traverse(a, b, false);
    while (true) {
        ++b;
        traverse(a, b, true);
        ++a;
        traverse(a, b, false);
    }

    return 0;
}
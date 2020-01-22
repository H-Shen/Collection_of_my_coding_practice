#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

auto isLeap = [](const int &n)->bool {
    return n % 400 == 0 || (n % 4 == 0 && n % 100 != 0);
};

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    int y, m;
    scanf("%d %d", &y, &m);
    if (isLeap(y)) {
        month[2] = 29;
    }
    printf("%d\n", month[m]);

    return 0;
}
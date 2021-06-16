// https://open.kattis.com/problems/powersof2easy

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    int n, e;
    scanf("%d %d", &n, &e);
    string s = to_string((int)pow(2, e));
    int counter = 0;
    char k_str[10];
    for (int k = 0; k <= n; ++k) {
        sprintf(k_str, "%d", k);
        if (strstr(k_str, s.c_str())) {
            ++counter;
        }
    }
    printf("%d\n", counter);
    return 0;
}

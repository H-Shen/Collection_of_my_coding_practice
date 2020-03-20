// https://open.kattis.com/problems/twostones
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int n;
    scanf("%d", &n);
    if (n & 1) {
        printf("Alice\n");
    } else {
        printf("Bob\n");
    }
    return 0;
}

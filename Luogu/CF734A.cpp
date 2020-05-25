#include <bits/extc++.h>

using namespace std;
constexpr int MAXN = 100005;
char s[MAXN];

int main(int argc, char *argv[]) {

    int n;
    scanf("%d %s", &n, s);
    int a = 0, b = 0;
    for (int i = 0; s[i] != 0; ++i) {
        if (s[i] == 'A') {
            ++a;
        } else {
            ++b;
        }
    }
    if (a > b) {
        puts("Anton");
    } else if (a == b) {
        puts("Friendship");
    } else {
        puts("Danik");
    }

    return 0;
}
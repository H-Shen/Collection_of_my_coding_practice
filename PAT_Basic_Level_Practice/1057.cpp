#include <bits/stdc++.h>

using namespace std;
const int maxn = 100005, gap = 'a' - 1;
char s[maxn];

int main() {
    scanf("%[^\n]", s);
    getchar();
    string str = s;
    char tmp;
    int sum = 0;

    for (const auto &i : str) {
        if (isalpha(i)) {
            tmp = tolower(i);
            sum = sum + tmp - gap;
        }
    }
    int cntZero = 0, cntOne = 0;
    while (sum > 0) {
        if (sum % 2 == 0) {
            ++cntZero;
        } else {
            ++cntOne;
        }
        sum /= 2;
    }
    printf("%d %d\n", cntZero, cntOne);
    return 0;
}

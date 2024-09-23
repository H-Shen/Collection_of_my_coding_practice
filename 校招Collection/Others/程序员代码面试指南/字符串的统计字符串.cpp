// https://www.nowcoder.com/practice/e8b97a6d64ae4304b6f0ff4ecae1589d

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100005;
char s[MAXN];

int main() {

    scanf("%s", s);
    char currentChar = s[0];
    int counter = 1;
    bool firstItem = true;
    for (int i = 1; s[i] != '\0'; ++i) {
        if (s[i] == currentChar) {
            ++counter;
        } else {
            // output
            if (firstItem) {
                firstItem = false;
            } else {
                printf("_");
            }
            printf("%c_%d", currentChar, counter);
            currentChar = s[i];
            counter = 1;
        }
    }
    // output
    if (!firstItem) {
        printf("_");
    }
    printf("%c_%d\n", currentChar, counter);
    return 0;
}
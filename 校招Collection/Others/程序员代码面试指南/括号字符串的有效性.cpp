// https://www.nowcoder.com/practice/769abd985f3849d0b9415b082f94c192

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 100005;
char s[MAXN];

int main() {

    stack<char> A;
    scanf("%s", s);
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] != '(' && s[i] != ')') {
            printf("NO\n");
            return 0;
        }
        if (s[i] == '(') {
            A.push(s[i]);
        } else {
            if (A.empty()) {
                printf("NO\n");
                return 0;
            }
            else {
                A.pop();
            }
        }
    }
    if (!A.empty()) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }

    return 0;
}
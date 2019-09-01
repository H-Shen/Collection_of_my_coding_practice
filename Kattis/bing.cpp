// https://open.kattis.com/problems/bing
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 35;
char s[MAXN];
unordered_map<string_view, int> A;

int main() {

    int n;
    string_view str;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", s);
        str = s;
        if (A.find(str) == A.end()) {
            printf("0\n");
        } else {
            printf("%d\n", A[str]);
        }
        for (size_t i = 1; i <= str.size(); ++i) {
            ++A[str.substr(0, i)];
        }
    }

    return 0;
}

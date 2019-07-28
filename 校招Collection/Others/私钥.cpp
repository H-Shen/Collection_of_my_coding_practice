// https://www.nowcoder.com/practice/5f660caeeed04543b59250cae5218bd8

#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 200;
char s[maxn];

int main() {
    int n, k, i, j;
    string str;
    while (~scanf("%d %d", &n, &k)) {
        vector<int> A(static_cast<unsigned long>(n));
        for (i = 0; i < n; ++i) {
            scanf("%d", &A[i]);
        }
        scanf("%s", s);
        str = s;
        if (static_cast<int>(str.size()) < n) {
            str += string(n - str.size(), ' ');
        }
        for (i = 0; i < k; ++i) {
            vector<char> res(static_cast<unsigned long>(n), ' ');
            for (j = 0; j < n; ++j) {
                res[A[j] - 1] = str[j];
            }
            str = "";
            for (j = 0; j < n; ++j) {
                str += res[j];
            }
        }
        printf("%s\n", str.c_str());
    }


    return 0;
}
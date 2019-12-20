// https://www.nowcoder.com/practice/e172dbac7d9140e98eef66c9ebbe25f8

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;
char s[MAXN];
unordered_map<string, int> A;

int main() {

    scanf("%[^\n]", s);
    string str = s;
    int n = static_cast<int>(str.size());
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            ++A[str.substr(i, j - i + 1)];
        }
    }
    int maxVal = 0;
    for (const auto &i : A) {
        if (i.second >= 2) {
            maxVal = max(maxVal, static_cast<int>(i.first.size()));
        }
    }
    printf("%d\n", maxVal);

    return 0;
}
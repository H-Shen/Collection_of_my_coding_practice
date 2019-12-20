// https://www.nowcoder.com/practice/e947e4801fc64808b2390c1cf2754906

#include <cstdio>
#include <cstring>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int MAXN = 105;
char a[MAXN], b[MAXN];

int main() {

    scanf("%[a-zA-Z0-9],%[a-zA-Z0-9]", a, b);
    string str_a = a;
    string str_b = b;
    size_t maxLen = 0;

    for (size_t i = 0; i < str_a.size(); ++i) {
        for (size_t j = i; j < str_a.size(); ++j) {
            // from str_a[i] to str_a[j]
            if (str_b.find(str_a.substr(i, j - i + 1)) != string::npos) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    cout << maxLen << endl;

    return 0;
}
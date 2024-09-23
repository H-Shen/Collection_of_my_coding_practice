#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
char s[MAXN];

int main() {
    char ch;
    string str;
    scanf("%c", &ch);
    getchar();
    int len, i, cnt;
    char lastChar = 'a';
    string res;
    string num;

    scanf("%[^\n]", s);
    str = s;
    len = static_cast<int>(str.size());

    if (ch == 'C') {
        cnt = 0;
        for (i = 0; i < len; ++i) {
            if (i == 0) {
                lastChar = str[i];
                ++cnt;
            } else if (str[i] == lastChar) {
                ++cnt;
            } else {
                if (cnt == 1) {
                    res += lastChar;
                } else {
                    res += to_string(cnt) + lastChar;
                }
                lastChar = str[i];
                cnt = 1;
            }
        }
        if (cnt != 0) {
            if (cnt == 1) {
                res = res + lastChar;
            } else {
                res = res + to_string(cnt) + lastChar;
            }
        }
    } else {
        for (i = 0; i < len; ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                num += str[i];
            } else {
                if (num.empty()) {
                    res += str[i];
                } else {
                    res = res + string(static_cast<size_t>(stoi(num)), str[i]);
                    num = "";
                }
            }
        }
    }
    printf("%s\n", res.c_str());
    return 0;
}
// https://ac.nowcoder.com/acm/problem/13814

#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
char s[maxn];
unordered_set<char> A = {'0', '2', '4', '6', '9'};

int main() {
    int n, len, i;
    scanf("%d", &n);
    string res, str;
    getchar();
    while (n--) {
        res = "";
        scanf("%s", s);
        str = s;
        len = str.size();
        i = 0;
        while (i < len) {
            if (A.find(str[i]) != A.end()) {
                res += str[i];
                ++i;
            } else if (str[i] == 'z') {
                if (i + 4 <= len && str.substr(i, 4) == "zero") {
                    res = res + "0";
                    i += 4;
                } else {
                    ++i;
                }
            } else if (str[i] == 'n') {
                if (i + 4 <= len && str.substr(i, 4) == "nine") {
                    res = res + "9";
                    i += 4;
                } else {
                    ++i;
                }
            } else if (str[i] == 'f') {
                if (i + 4 <= len && str.substr(i, 4) == "four") {
                    res = res + "4";
                    i += 4;
                } else {
                    ++i;
                }
            } else if (str[i] == 't') {
                if (i + 3 <= len && str.substr(i, 3) == "two") {
                    res = res + "2";
                    i += 3;
                } else {
                    ++i;
                }
            } else if (str[i] == 's') {
                if (i + 3 <= len && str.substr(i, 3) == "six") {
                    res = res + "6";
                    i += 3;
                } else {
                    ++i;
                }
            } else {
                ++i;
            }
        }
        printf("%s\n", res.c_str());
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

string convert(string &s) {
    string res;
    if (s.empty()) {
        return res;
    }
    char lastChar = s[0];
    int len = static_cast<int>(s.size());
    int cnt = 1;
    for (int i = 1; i < len; ++i) {
        if (s[i] == lastChar) {
            ++cnt;
        } else {
            res += lastChar + to_string(cnt);
            cnt = 1;
            lastChar = s[i];
        }
    }
    res = res + lastChar + to_string(cnt);
    return res;
}

int main() {
    char ch;
    string s;
    int n, i;
    scanf("%c %d", &ch, &n);
    s = ch;
    for (i = 0; i < n - 1; ++i) {
        s = convert(s);
    }

    printf("%s\n", s.c_str());
    return 0;
}
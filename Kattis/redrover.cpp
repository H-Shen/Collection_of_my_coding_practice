// https://open.kattis.com/problems/redrover
//
#include <bits/stdc++.h>

using namespace std;
constexpr int MAXLEN = 105;
char s[MAXLEN];

static const string macro = "M";

int main() {

    scanf("%s", s);
    string str(s);
    string strCopy;
    string pattern;
    size_t minLen = str.size();
    for (size_t i = 0; i != str.size(); ++i) {
        for (size_t j = i; j != str.size(); ++j) {
            strCopy = str;
            pattern = str.substr(i, j - i + 1);
            strCopy = regex_replace(strCopy, regex(pattern), macro);
            minLen = min(minLen, strCopy.size() + pattern.size());
        }
    }
    printf("%lu\n", minLen);

    return 0;
}

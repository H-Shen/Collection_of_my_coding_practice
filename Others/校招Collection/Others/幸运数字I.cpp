// https://ac.nowcoder.com/acm/problem/15290

#include <bits/stdc++.h>

using namespace std;
const int maxn = 55;
char str[maxn];

int main()
{
    vector <int> unluckyNumberPosSave;
    unordered_map <string, int> luckyNumberSave;

    scanf("%s", str);
    string s = str;
    int i, j;
    int len = static_cast<int>(s.size());

    for (i = 0; i < len; ++i) {
        if (s[i] != '4' && s[i] != '7') {
            unluckyNumberPosSave.push_back(i);
        }
    }

    bool hasUnluckyNumber;
    for (i = 0; i < len; ++i) {
        for (j = i + 1; j < len + 1; ++j) {
            hasUnluckyNumber = false;
            for (const auto & p : unluckyNumberPosSave) {
                if (p >= i && p <= j - 1) {
                    hasUnluckyNumber = true;
                    break;
                }
            }
            if (!hasUnluckyNumber) {
                ++luckyNumberSave[s.substr(i, j - i)];
            }
        }
    }

    int maxFreq = -1;
    string smallestString;
    for (const auto & it : luckyNumberSave) {
        maxFreq = max(maxFreq, it.second);
    }
    for (const auto & it : luckyNumberSave) {
        if (it.second == maxFreq) {
            if (smallestString.empty()) {
                smallestString = it.first;
            }
            else {
                smallestString = min(smallestString, it.first);
            }
        }
    }
    if (smallestString.empty()) {
        printf("-1\n");
    }
    else {
        printf("%s\n", smallestString.c_str());
    }
    return 0;
}